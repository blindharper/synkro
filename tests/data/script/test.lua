-----------------------------
-- Functions
-----------------------------
function this.test( this, text, text2 )
	local n = this:echo( text );
	local n2 = this:echo( text2 );
	return n+n2
end

-----------------------------
-- Entry point
-----------------------------
this:echo( "Directly calling echo()" );
local num = this:test( "Test string #1", "Test string #2" );
io.write( string.format("Total characters printed: %d\n",num) );

local child1 = this:spawn( "First Child" );
local child2 = this:spawn( "Second Child" );
this:echo( child1:getName() );
this:echo( child2:getName() );
