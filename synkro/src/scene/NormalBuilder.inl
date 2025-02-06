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
// Purpose: Normal builder helper.
//==============================================================================
template <class I>
void NormalBuilder::GenerateNormals( const I* indices, UInt indexCount, const math::Vector3* vertices, math::Vector3* normals, Bool smooth )
{
	I maxIdx = 0;
	math::Vector3 pos[3]; math::Vector3 a; math::Vector3 b; math::Vector3 n;
	for ( UInt i = 0; i < indexCount; i += 3 )
	{
		// Remember maximum index.
		if ( maxIdx < indices[i+0] ) { maxIdx = indices[i+0]; }
		if ( maxIdx < indices[i+1] ) { maxIdx = indices[i+1]; }
		if ( maxIdx < indices[i+2] ) { maxIdx = indices[i+2]; }

		// Retrieve face vertices.
		pos[0] = vertices[indices[i+0]];
		pos[1] = vertices[indices[i+1]];
		pos[2] = vertices[indices[i+2]];

		// Calculate face normal.
		a = pos[1] - pos[0];
		b = pos[2] - pos[0];
		n = a ^ b;
		n.Normalize();

		// Save normals.
		normals[indices[i+0]] = normals[indices[i+1]] = normals[indices[i+2]] = n;
	}

	// Make normals smooth.
	if ( smooth )
	{
		for ( I j = 0; j <= maxIdx; ++j )
		{
			// Calculate average normal for the vertex.
			n.x = n.y = n.z = 0.0f;
			for ( UInt i = 0; i < indexCount; ++i )
			{
				if ( indices[i] == j )
				{
					n += normals[j];
				}
			}
			n.Normalize();

			// Update normals.
			for ( UInt i = 0; i < indexCount; ++i )
			{
				if ( indices[i] == j )
				{
					normals[j] = n;
				}
			}
		}
	}
}
