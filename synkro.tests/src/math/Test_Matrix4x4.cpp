#include "config.h"
#include "Test.h"
#include <math/Matrix4x4.h>
#include <math/Math.h>

//------------------------------------------------------------------------------

using namespace synkro::math;
using namespace synkro;

//------------------------------------------------------------------------------

class TestMatrix4x4 :
	public Test
{
public:
	TestMatrix4x4() : Test( "TestMatrix4x4", 702 ) {}

	void Run()
	{
		// Creation.
		Matrix4x4 mat0( 1.0f );
		Assert( mat0.m[3][3] == 1.0f );
		Assert( mat0.IsIdentity() );

		Matrix4x4 mat1( mat0 );
		Assert( mat0 == mat1 )
		Assert( mat1.IsIdentity() );

		// Addition.
		mat1 += mat0;
		Assert( (mat1.m[0][0] == 2.0f) && (mat1.m[1][1] == 2.0f) && (mat1.m[2][2] == 2.0f) );

		// Multiplication.
		Matrix4x4 mat2( 0.1f, 0.2f, 0.3f, 0.4f,
						0.5f, 0.6f, 0.7f, 0.8f,
						0.9f, 1.0f, 1.1f, 1.2f,
						1.3f, 1.4f, 1.5f, 1.6f );

		Matrix4x4 mat3( 1.1f, 1.2f, 1.3f, 1.4f,
						1.5f, 1.6f, 1.7f, 1.8f,
						1.9f, 2.0f, 2.1f, 2.2f,
						2.3f, 2.4f, 2.5f, 2.6f );

		Matrix4x4 mat4 = mat3 * mat2;
		Assert( Math::Abs(mat4._00 - 1.9f) < Math::Eps );
		Assert( Math::Abs(mat4._01 - 2.0f) < Math::Eps );
		Assert( Math::Abs(mat4._02 - 2.1f) < Math::Eps );
		Assert( Math::Abs(mat4._03 - 2.2f) < Math::Eps );

		Assert( Math::Abs(mat4._10 - 4.62f) < Math::Eps );
		Assert( Math::Abs(mat4._11 - 4.88f) < Math::Eps );
		Assert( Math::Abs(mat4._12 - 5.14f) < Math::Eps );
		Assert( Math::Abs(mat4._13 - 5.4f) < Math::Eps );

		Assert( Math::Abs(mat4._20 - 7.34f) < Math::Eps );
		Assert( Math::Abs(mat4._21 - 7.76f) < Math::Eps );
		Assert( Math::Abs(mat4._22 - 8.18f) < Math::Eps );
		Assert( Math::Abs(mat4._23 - 8.6f) < Math::Eps );

		Assert( Math::Abs(mat4._30 - 10.06f) < Math::Eps );
		Assert( Math::Abs(mat4._31 - 10.64f) < Math::Eps );
		Assert( Math::Abs(mat4._32 - 11.22f) < Math::Eps );
		Assert( Math::Abs(mat4._33 - 11.8f) < Math::Eps );

		// Look At.
		Vector3 vecEye( 5.0f, 5.0f, 6.5f );
		Vector3 vecAt( 0.0f, 0.0f, 1.0f );
		Vector3 vecUp( 0.0f, 0.0f, 1.0f );

		Matrix4x4 matView;
		matView.SetLookAt( vecAt, vecEye, vecUp );
		Assert( Math::Abs(matView._00 - 0.70710677f) < Math::Eps );
		Assert( Math::Abs(matView._01 - -0.43413529f) < Math::Eps );
		Assert( Math::Abs(matView._02 - -0.55814552f) < Math::Eps );
		Assert( Math::Abs(matView._03 - 0.0f) < Math::Eps );

		Assert( Math::Abs(matView._10 - -0.70710677f) < Math::Eps );
		Assert( Math::Abs(matView._11 - -0.43413529f) < Math::Eps );
		Assert( Math::Abs(matView._12 - -0.55814552f) < Math::Eps );
		Assert( Math::Abs(matView._13 - 0.0f) < Math::Eps );

		Assert( Math::Abs(matView._20 - 0.0f) < Math::Eps );
		Assert( Math::Abs(matView._21 - 0.78933698f) < Math::Eps );
		Assert( Math::Abs(matView._22 - -0.61396003f) < Math::Eps );
		Assert( Math::Abs(matView._23 - 0.0f) < Math::Eps );

		Assert( Math::Abs(matView._30 - 0.0f) < Math::Eps );
		Assert( Math::Abs(matView._31 - -0.789337f) < Math::Eps );
		Assert( Math::Abs(matView._32 - 9.5721951f) < Math::Eps );
		Assert( Math::Abs(matView._33 - 1.0f) < Math::Eps );

		// Determinant.
		Matrix4x4 def;
		Assert( def.Determinant() == 1.0f );

		// Inversion.
		Matrix4x4 identity( 1.0f );
		Matrix4x4 org( 1.0f,  2.0f, 3.0f, 4.0f, 
					   8.0f,  7.0f, 6.0f, 5.0f,
					  -3.0f,  4.0f, 2.6f, -4.7f,
					   4.6f,  3.0f, 8.1f, 1.0f );
		Matrix4x4 inv = org.Inverse();
		Assert( org.Determinant() != 0.0f );

		Matrix4x4 org1 = org*inv;
		Assert( Math::Abs(org1._00 - 1.0f) < Math::Eps );
		Assert( Math::Abs(org1._11 - 1.0f) < Math::Eps );
		Assert( Math::Abs(org1._22 - 1.0f) < Math::Eps );
		Assert( Math::Abs(org1._33 - 1.0f) < Math::Eps );

		Matrix4x4 org2 = inv*org;
		Assert( Math::Abs(org2._00 - 1.0f) < Math::Eps );
		Assert( Math::Abs(org2._11 - 1.0f) < Math::Eps );
		Assert( Math::Abs(org2._22 - 1.0f) < Math::Eps );
		Assert( Math::Abs(org2._33 - 1.0f) < Math::Eps );

		// Rotation.
		Float angle = Math::ToRadians( 90.0f );
		Matrix4x4 m1;
		Matrix4x4 m2;
		m1 = m1.RotateZ( angle );
		m2 = m2.Rotate( Vector3(0.0f, 0.0f, 1.0f), angle );
		Assert( m1 == m2 );

		// Vector transformation.
		Vector3 nX( 1.0f, 0.0f, 0.0f );
		Vector3 nY( 0.0f, 1.0f, 0.0f );
		Vector3 vecTrans = m1*nX;
		Assert( Math::Abs(vecTrans.x - nY.x) < Math::Eps );
		Assert( Math::Abs(vecTrans.y - nY.y) < Math::Eps );
		Assert( Math::Abs(vecTrans.z - nY.z) < Math::Eps );
	}

} _tst;
