/*************** <auto-copyright.pl BEGIN do not edit this line> **************
 *
 * osgWorks is (C) Copyright 2009-2011 by Kenneth Mark Bryden
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/

#ifndef __OSGWQUERY_QUERY_API_H__
#define __OSGWQUERY_QUERY_API_H__ 1


#include <osgwQuery/Export.h>
#include <osg/Referenced>
#include <osg/GL>

// Contains typedefs for GLuint64EXT and GLint64EXT
#include <osg/Drawable>

// v1.5
#ifndef GL_SAMPLES_PASSED
#  define GL_SAMPLES_PASSED = 0x8914
#endif

// v3.0 / GL_EXT_transform_feedback
#ifndef GL_PRIMITIVES_GENERATED
#  define GL_PRIMITIVES_GENERATED = 0x8C87
#endif
#ifndef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
#  define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88
#endif

// v3.3 / GL_ARB_occlusion_query2
#ifndef GL_ANY_SAMPLES_PASSED
#  define GL_ANY_SAMPLES_PASSED = 0x8C2F
#endif

// v3.3 / GL_ARB_timer_query
#ifndef GL_TIME_ELAPSED
#  define GL_TIME_ELAPSED = 0x88BF
#endif


namespace osgwQuery
{


/** \class QueryAPI QueryAPI.h <osgwQuery/QueryAPI.h>
\brief A conveniece wrapper class for OpenGL query API entry points.
*/
class OSGWQUERY_EXPORT QueryAPI : public osg::Referenced
{
public:
    QueryAPI( unsigned int contextID );

    void glBeginQuery( GLenum target, GLuint id );
    void glEndQuery( GLenum target );
    void glGenQueries( GLsizei n, GLuint *ids );
    void glDeleteQueries( GLsizei n, const GLuint *ids );
    GLboolean glIsQuery( GLuint id );
    void glGetQueryiv( GLenum target, GLenum pname, int *params );
    void glGetQueryObjectiv( GLuint id, GLenum pname, GLint *params );
    void glGetQueryObjectuiv( GLuint id, GLenum pname, GLuint *params );

    // v3.3 / GL_ARB_timer_query
    void glGetQueryObjecti64v( GLuint id, GLenum pname, GLint64EXT *params );
    void glGetQueryObjectui64v( GLuint id, GLenum pname, GLuint64EXT *params );

    // GL v4.0 / GL_ARB_transform_feedback3
    void glBeginQueryIndexed( GLenum target, GLuint index, GLuint id );
    void glEndQueryIndexed( GLenum target, GLuint index );
    void glGetQueryIndexediv( GLenum target, GLuint index, GLenum pname, GLint *params );

protected:
    ~QueryAPI();

    void internalInit( unsigned int contextID );
    bool _initialized;

    bool _queryAPISupported;
    bool _timerQuerySupported;
    bool _transformFeedback3Supported;
    bool _transformFeedbackSupported;
    bool _occlusionQuery2Supported;

    typedef void (APIENTRY *BeginQueryProc) (GLenum target, GLuint id);
    typedef void (APIENTRY *EndQueryProc) (GLenum target);
    typedef void (APIENTRY *GenQueriesProc) (GLsizei n, GLuint *ids);
    typedef void (APIENTRY *DeleteQueriesProc) (GLsizei n, const GLuint *ids);
    typedef GLboolean (APIENTRY *IsQueryProc) (GLuint id);
    typedef void (APIENTRY *GetQueryivProc) (GLenum target, GLenum pname, GLint *params);
    typedef void (APIENTRY *GetQueryObjectivProc) (GLuint id, GLenum pname, GLint *params);
    typedef void (APIENTRY *GetQueryObjectuivProc) (GLuint id, GLenum pname, GLuint *params);
    typedef void (APIENTRY *GetQueryObjecti64vProc)( GLuint id, GLenum pname, GLint64EXT *params );
    typedef void (APIENTRY *GetQueryObjectui64vProc) (GLuint id, GLenum pname, GLuint64EXT *params);
    typedef void (APIENTRY *BeginQueryIndexedProc)( GLenum target, GLuint index, GLuint id );
    typedef void (APIENTRY *EndQueryIndexedProc)( GLenum target, GLuint index );
    typedef void (APIENTRY *GetQueryIndexedivProc)( GLenum target, GLuint index, GLenum pname, GLint *params );

    BeginQueryProc _beginQuery;
    EndQueryProc _endQuery;
    GenQueriesProc _genQueries;
    DeleteQueriesProc _deleteQueries;
    IsQueryProc _isQuery;
    GetQueryivProc _getQueryiv;
    GetQueryObjectivProc _getQueryObjectiv;
    GetQueryObjectuivProc _getQueryObjectuiv;
    GetQueryObjecti64vProc _getQueryObjecti64v;
    GetQueryObjectui64vProc _getQueryObjectui64v;
    BeginQueryIndexedProc _beginQueryIndexed;
    EndQueryIndexedProc _endQueryIndexed;
    GetQueryIndexedivProc _getQueryIndexediv;
};


/**
*/
QueryAPI* getQueryAPI( unsigned int contextID );


// osgwQuery
}

// __OSGWQUERY_QUERY_API_H__
#endif