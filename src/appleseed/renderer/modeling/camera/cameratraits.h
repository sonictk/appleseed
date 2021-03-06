
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2016 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_RENDERER_MODELING_CAMERA_CAMERATRAITS_H
#define APPLESEED_RENDERER_MODELING_CAMERA_CAMERATRAITS_H

// appleseed.renderer headers.
#include "renderer/modeling/camera/camera.h"
#include "renderer/modeling/entity/entitytraits.h"

// appleseed.foundation headers.
#include "foundation/utility/containers/dictionary.h"
#include "foundation/utility/autoreleaseptr.h"

// Forward declarations.
namespace renderer  { class CameraFactoryRegistrar; }

namespace renderer
{

//
// Camera entity traits.
//

template <>
struct EntityTraits<Camera>
{
    typedef CameraFactoryRegistrar FactoryRegistrarType;

    static const char* get_entity_type_name()                   { return "camera"; }
    static const char* get_human_readable_entity_type_name()    { return "Camera"; }

    static foundation::Dictionary get_entity_values(const Camera* entity)
    {
        return entity->get_parameters();
    }

    template <typename ParentEntity>
    static void insert_entity(
        foundation::auto_release_ptr<Camera>        entity,
        ParentEntity&                               parent)
    {
        parent.set_camera(entity);
    }

    template <typename ParentEntity>
    static void remove_entity(
        Camera*                                     entity,
        ParentEntity&                               parent)
    {
        parent.set_camera(foundation::auto_release_ptr<Camera>(0));
    }
};

}       // namespace renderer

#endif  // !APPLESEED_RENDERER_MODELING_CAMERA_CAMERATRAITS_H
