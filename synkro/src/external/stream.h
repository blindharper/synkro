//==============================================================================
// This file stream a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Declares generic stream interface.
//==============================================================================

#ifdef  __cplusplus
extern "C" {
#endif

void* streamopen( void* stream, const char* mode );
void* streamcloneappend( void* stream, const char* suffix );
void streamclose( void* stream );
void streamflush( void* stream );
void streamdelete( void* stream );
void streamsetsize( void* stream, unsigned int size );
unsigned int streamsize( void* stream );
unsigned int streamtell( void* stream );
unsigned int streamseek( void* stream, long offset, int origin );
unsigned int streamread( void* buffer, unsigned int size, unsigned int count, void* stream );
unsigned int streamreadoffset( void* buffer, unsigned int size, unsigned int count, long offset, void* stream );
unsigned int streamwrite( const void* buffer, unsigned int size, unsigned int count, void* stream );
unsigned int streamwriteoffset( const void* buffer, unsigned int size, unsigned int count, long offset, void* stream );

#ifdef  __cplusplus
}
#endif
