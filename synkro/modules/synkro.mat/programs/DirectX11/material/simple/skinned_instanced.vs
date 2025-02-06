//------------------------------------------------------------------------------
// File: skinned_instanced.vs
//
// Purpose: Vertex shader for skinned instanced simple material
//------------------------------------------------------------------------------
#include "../viewport.vsh"

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

#define MAX_BONE_COUNT	50			// Maximum number of bone matrices

//------------------------------------------------------------------------------
// Structures
//------------------------------------------------------------------------------

// Vertex shader input data
struct Vertex
{
	float3 pos	: POSITION;		// Vertex position
	float4 weights	: WEIGHTS;		// Vertex bone weights
	uint4 bones	: BONES;		// Vertex bone indices
	float4x4 trans	: TRANSFORM0;		// Instance transformation matrix (TRANSFORM0-TRANSFORM3)
	float4 col	: COLOR0;		// Instance color
	uint InstanceId : SV_InstanceID;	// Instance ID
};

// Fragment shader input data
struct Fragment
{
	float4 pos	: SV_POSITION;		// Fragment position
	float4 col	: COLOR0;		// Fragment color
	float dist	: DISTANCE;		// Distance to camera
};

//------------------------------------------------------------------------------
// Resources
//------------------------------------------------------------------------------
Buffer<float4>	bufBones;			// Bones transforms

//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------
float4x4 GetBoneTransform( uint instance, uint bone )
{
	uint idx = instance*MAX_BONE_COUNT + bone;

	idx *= 4;
	float4 row1 = bufBones.Load( idx );
	float4 row2 = bufBones.Load( idx+1 );
	float4 row3 = bufBones.Load( idx+2 );
	float4 row4 = bufBones.Load( idx+3 );

	return float4x4( row1, row2, row3, row4 );
}

//------------------------------------------------------------------------------
// Entry point
//------------------------------------------------------------------------------
Fragment main( Vertex vertex )
{
	Fragment fragment = (Fragment)0.0f;

	float4 pos = float4( vertex.pos, 1.0f );

	fragment.pos += vertex.weights.x * mul( pos, GetBoneTransform(vertex.InstanceId, vertex.bones.x) );
	fragment.pos += vertex.weights.y * mul( pos, GetBoneTransform(vertex.InstanceId, vertex.bones.y) );
	fragment.pos += vertex.weights.z * mul( pos, GetBoneTransform(vertex.InstanceId, vertex.bones.z) );
	fragment.pos += vertex.weights.w * mul( pos, GetBoneTransform(vertex.InstanceId, vertex.bones.w) );

	fragment.pos = mul( fragment.pos, vertex.trans );
	float4 worldPos = fragment.pos;
	float4 cameraPos = mul( worldPos, sp_view );
	
	fragment.pos = mul( fragment.pos, sp_worldViewProj );
	fragment.col = vertex.col;
	fragment.dist = cameraPos.z;

	return fragment;
}
