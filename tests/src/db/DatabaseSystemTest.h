#include <db/IDatabaseSystemFactory.h>
#include <db/IDatabaseSystem.h>
#include <db/IDatabase.h>
#include <db/IDataTable.h>
#include <db/IDataFilter.h>
#include <db/IInsertQuery.h>
#include <db/IUpdateQuery.h>
#include <db/ISelectQuery.h>
#include <db/IDeleteQuery.h>
#include <db/IDataCursor.h>
#include <db/DataFilter.h>
#include <io/Win32/Win32Directory.h>
#include <lang/Vector.h>
#include <lang/Ptr.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::db;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

class DatabaseSystemTest
{
public:
	DatabaseSystemTest( const String& name, const String& dir, const String& database, IDatabaseSystemFactory* factDatabaseSys ) :
		_name( name ),
		_dir( dir ),
		_database( database ),
		_factDatabaseSys( factDatabaseSys )
	{
	}

	void Run()
	{
		P(IStreamDirectory) dir = new Win32Directory( nullptr, _dir, nullptr );

		P(IStream) stream = dir->CreateStream( _database );
		IDatabaseSystem* databaseSystem = _factDatabaseSys->Create( nullptr );
		P(IDatabase) db = databaseSystem->CreateDatabase( stream );

		// Schema creation.
		TableColumn columns[] =
		{
			{L"id", DataType::Integer, true, false, true},
			{L"name", DataType::String, false, false, false},
		};
		IDataTable* tblRenderView = db->GetTable( L"render_view" );
		if ( tblRenderView == nullptr )
		{
			tblRenderView = db->CreateTable( L"render_view", columns, 2 );
		}
		if ( tblRenderView->GetIndex(L"idx_render_view") == nullptr )
		{
			String colName( columns[1].Name );
			tblRenderView->CreateIndex( L"idx_render_view", true, &colName, 1 );
		}

		TableColumn columns2[] =
		{
			{L"id", DataType::Integer, true, false, true},
			{L"view_id", DataType::Integer, false, false, false, L"render_view", L"id"},
			{L"data", DataType::Blob, false, true, false},
		};
		IDataTable* tblFilter = db->GetTable( L"render_view_filter" );
		if ( tblFilter == nullptr )
		{
			tblFilter = db->CreateTable( L"render_view_filter", columns2, 3 );
		}

		// Insertion.
		P(IInsertQuery) insert = tblRenderView->CreateInsertQuery();
		insert->SetValue( L"id", 888L );
		insert->SetValue( L"name", L"John is a busy man." );
		insert->Execute();

		insert = tblRenderView->CreateInsertQuery();
		insert->SetValue( L"id", 666L );
		insert->SetValue( L"name", L"Eugene is a programmer!!!" );
		insert->Execute();
		UInt row = insert->GetRowID();

		Byte data[] = { 0x98, 0x97, 0x96, 0x95 };
		insert = tblFilter->CreateInsertQuery();
		insert->SetValue( L"id", 111L );
		insert->SetValue( L"view_id", 888L );
		insert->SetValue( L"data", Variant(data, 4) );
		insert->Execute();

		// Selection.
		UInt cnt = tblRenderView->GetRowCount();
		wprintf( L"View Rows: %d\n", cnt );

		P(ISelectQuery) select = tblRenderView->CreateSelectQuery();
		select->SelectAll();
		select->Sort( L"name", SortOrder::Asc );
		select->Execute();
		IDataCursor* cursor = select->GetCursor();
		Vector<Char> blob( A(Char) );
		while ( cursor->Read() )
		{
			Variant id = cursor->GetValue( L"id" );
			Variant name = cursor->GetValue( L"name" );
			String str = (String)name;
			blob.SetSize( str.Length() );
			str.GetChars( 0, str.Length(), blob.Begin() );
			wprintf( L"Record: id=%d, name=%s\n", (Int)id, blob.Begin() );
		}

		// Update.
		P(IUpdateQuery) update = tblFilter->CreateUpdateQuery();
		update->SetFilter( new DataFilter(L"view_id", ComparisonType::NotEqual, Variant(888L)) );
		update->SetValue( L"data", Variant((Byte*)blob.Begin(), blob.Size()) );
		update->Execute();

		// Deletion.
		P(IDeleteQuery) del = tblFilter->CreateDeleteQuery();
		del->SetFilter( new DataFilter(L"view_id", ComparisonType::Equal, Variant(888L)) );
		del->Execute();

		del = tblRenderView->CreateDeleteQuery();
		del->SetFilter( new DataFilter(L"id", ComparisonType::Equal, Variant(888L)) );
		del->Execute();

		del = tblRenderView->CreateDeleteQuery();
		del->SetFilter( new DataFilter(L"id", ComparisonType::Equal, Variant(666L)) );
		del->Execute();
	}

private:
	String					_name;
	String					_dir;
	String					_database;
	IDatabaseSystemFactory*	_factDatabaseSys;
};
