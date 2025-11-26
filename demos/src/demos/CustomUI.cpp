#include "../Demo.h"


class CustomUI :
	public Demo,
	public ProgressListener
{
public:
	CustomUI() :
		Demo( L"CustomUI" ),
		_task( nullptr )
	{
	}

	void InitScene() override
	{
		PtrStream stream = GetStream( L"cell.x" );
		_cell = _scene->LoadMesh( stream, nullptr, nullptr, 0 );
		INodeAnimationController* ctrlCell = _cell->CreateAnimationController( nullptr, nullptr );
		PtrWaveFloatTrack trackYaw = ctrlCell->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
		trackYaw->SetType( WaveType::SawtoothDown );
		trackYaw->SetAmplitude( Math::TwoPi );
		trackYaw->SetFrequency( 1.0f/60.0f );
		ctrlCell->SetMode( AnimationMode::Loop );
		ctrlCell->Start( true );
	}

	void InitView() override
	{
		_camera->SetPosition( Vector3(0.0f, 1.5f, -8.0f) );
		_camera->LookAt( Vector3(0.0f, 0.7f, 0.0f) );
	}

	void InitUi() override
	{
		PtrStream stream = GetStream( L"CustomUI.ui" );
		_synkro->GetUi()->Load( stream );
		_label = _synkro->GetUi()->GetWidget( ID_LABEL )->AsLabel();
		_list = _synkro->GetUi()->GetWidget( ID_LIST )->AsList();
		_btnRemove = _synkro->GetUi()->GetWidget( ID_LIST_REMOVE )->AsButton();
		_btnRemove->Enable( false );

		_progressBar = _synkro->GetUi()->GetWidget( ID_PROGRESS_BAR )->AsProgress();
		_progressBar->ShowText( true );

		_labelBackup = _synkro->GetUi()->GetWidget( ID_LABEL_BACKUP )->AsLabel();
		_edit = _synkro->GetUi()->GetWidget( ID_EDIT )->AsEdit();
	}

	// UiListener methods.
	Bool OnUiClick( IWidget* sender ) override
	{
		if ( Demo::OnUiClick(sender) )
			return true;

		UInt index = 0;
		switch ( sender->ID() )
		{
			case ID_LIST_ADD:
				_list->AddItem( String::Format(L"Item #{0}", _list->GetItemCount()+1) );
				_btnRemove->Enable( true );
				return true;

			case ID_LIST_INSERT:
				index = (_list->GetSelectedItem() != none) ? _list->GetSelectedItem() : 0;
				_list->InsertItem( index, String::Format(L"Item #{0}", _list->GetItemCount()+1) );
				_btnRemove->Enable( true );
				return true;

			case ID_LIST_REMOVE:
				if ( _list->GetSelectedItem() != none )
				{
					_list->RemoveItem( _list->GetSelectedItem() );
					if ( _list->GetItemCount() == 0 )
					{
						_btnRemove->Enable( false );
					}
					return true;
				}
				break;

			case ID_TASK_RUN:
				if ( _task == nullptr )
				{
					_synkro->Execute( _task = new UiTask(this) );
					return true;
				}
				break;

			case ID_TASK_CANCEL:
				if ( _task != nullptr )
				{
					_task->Cancel();
					_progressBar->SetValue( 0 );
					return true;
				}
				break;

			case ID_EDIT_SAVE:
				_labelBackup->SetText( _edit->GetText() );
				return true;

			case ID_EDIT_RESTORE:
				_edit->SetText( _labelBackup->GetText() );
				return true;

			case ID_THEME_FLAT:
				_synkro->GetUi()->SetThemeName( ThemeName::Flat );
				return true;

			case ID_THEME_GLASS:
				_synkro->GetUi()->SetThemeName( ThemeName::Glass );
				return true;
		}

		return false;
	}

	Bool OnUiValueChanged( IWidget* sender ) override
	{
		if ( Demo::OnUiValueChanged(sender) )
			return true;

		switch ( sender->ID() )
		{
			case ID_LABEL_TRANSPARENT:
				_label->SetTransparent( sender->AsSwitch()->IsOn() );
				return true;

			case ID_LABEL_ALIGN_LEFT:
			case ID_LABEL_ALIGN_CENTER:
			case ID_LABEL_ALIGN_RIGHT:
				if ( sender->AsOption()->IsSelected() )
					_label->SetTextAlign( Alignment(sender->GetData()) );
				return true;
		}

		return false;
	}

	// ProgressListener methods.
	void OnProgressBegin( IObject* context, UInt total ) override
	{
		_progressBar->SetMaxValue( total );
	}

	void OnProgressUpdate( IObject* context, UInt current ) override
	{
		_progressBar->SetValue( current );
	}

	void OnProgressEnd( IObject* context ) override
	{
		_task = nullptr;
	}

private:
	enum
	{
		ID_LABEL = 100,
		ID_LABEL_TRANSPARENT = 101,
		ID_LABEL_ALIGN_LEFT = 102,
		ID_LABEL_ALIGN_CENTER = 103,
		ID_LABEL_ALIGN_RIGHT = 104,

		ID_LIST = 200,
		ID_LIST_ADD = 201,
		ID_LIST_INSERT = 202,
		ID_LIST_REMOVE = 203,

		ID_PROGRESS_BAR = 300,
		ID_TASK_RUN = 302,
		ID_TASK_CANCEL = 303,

		ID_LABEL_BACKUP = 400,
		ID_EDIT = 401,
		ID_EDIT_SAVE = 402,
		ID_EDIT_RESTORE = 403,

		ID_THEME_FLAT = 600,
		ID_THEME_GLASS = 601,
	};

	class UiTask :
		public Task
	{
	public:
		UiTask( ProgressListener* listener ) :
			_listener( listener ),
			_running( false ),
			_current( 0 )
		{
		}

		void Execute()
		{
			_listener->OnProgressBegin( nullptr, 100 );

			_running = true;
			for ( ; _running && (_current <= 100); ++_current )
			{
				Platform::Sleep( 100 );

				if ( _running )
				{
					_listener->OnProgressUpdate( nullptr, _current );
				}
			}
			_running = false;

			_listener->OnProgressEnd( nullptr );
		}

		void Cancel()
		{
			_running = false;
		}

	private:
		ProgressListener*	_listener;
		Bool				_running;
		UInt				_current;
	};

	PtrTriangleMesh											_cell;
	PtrLabel												_label;
	PtrList													_list;
	PtrButton												_btnRemove;

	PtrProgress												_progressBar;
	UiTask*													_task;

	PtrLabel												_labelBackup;
	PtrEdit													_edit;
};

SYNKRO_DEMO_BEGIN
	CustomUI demo;
	demo.Run();
SYNKRO_DEMO_END
