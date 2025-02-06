//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Defines generic tree container.
//==============================================================================
#ifndef _SYNKRO_LANG_TREE_
#define _SYNKRO_LANG_TREE_


#include "config.h"
#include "Allocator.h"
#include "TreeIterator.h"


namespace synkro
{


namespace lang
{


// Tree container holding elements of type T.
template <class T, class A = Allocator<TreeItem<T> > >
class Tree
{
public:
	// Constructs an empty tree.
	explicit Tree( const A& alloc );

	// Creates a copy of another tree.
	Tree( const Tree<T,A>& other );

	// Frees all allocated resources.
	~Tree();

	// Creates a copy of another tree.
	Tree<T,A>&												operator=( const Tree<T,A>& other );

	// Searches tree item children for the specified element.
	TreeIterator<T>											Find( const TreeIterator<T>& item, const T& elem, Bool recurse );

	// Searches tree item children for the specified element.
	TreeIterator<T>											Find( const TreeIterator<T>& item, const T& elem );

	// Searches tree item children for the specified element.
	TreeIterator<T>											Find( const T& elem, Bool recurse );

	// Searches tree item children for the specified element.
	TreeIterator<T>											Find( const T& elem );

	// Adds an element as item child.
	TreeIterator<T>											Add( const TreeIterator<T>& item, const T& elem );

	// Adds an element as root's immediate child.
	TreeIterator<T>											Add( const T& elem );

	// Removes item from the tree.
	Bool													Remove( const TreeIterator<T>& item );

	// Recursively removes all the child elements from the item.
	Bool													RemoveChildren( const TreeIterator<T>& item );

	// Removes all elements from the tree.
	void													Clear();

	// Performs tree traversal to depth in forward direction.
	// Should be called recursively to traverse the whole tree.
	// @param item Tree item from which to start traverse.
	// @return Next tree item on the traversal path.
	TreeIterator<T>											TraverseDepth( const TreeIterator<T>& item );

	// Retrieves iterator to the root of the tree.
	TreeIterator<T>											Root();

	// Retrieves constant iterator to the root of the tree.
	const TreeIterator<T>									Root() const;

	// Returns the number of elements in the tree.
	UInt													Size() const;

	// Returns true if the tree has no elements.
	Bool													IsEmpty() const;

	// Returns item's depth level.
	UInt													Depth( const TreeIterator<T>& item ) const;

	// Retrieves item's children count.
	UInt													ChildrenCount( const TreeIterator<T>& item, Bool recurse ) const;

	// Retrieves item's immediate children count.
	UInt													ChildrenCount( const TreeIterator<T>& item ) const;

	// Returns true if the tree item has at least one child element.
	Bool													HasChildren( const TreeIterator<T>& item ) const;

private:
	TreeItem<T>*											_root;
	A														_alloc;
	
	void													Copy( const Tree<T,A>& other );
	void													InternalCopy( TreeItem<T>** dst, TreeItem<T>* src );
};


#include "Tree.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_TREE_
