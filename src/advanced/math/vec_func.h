/*
 * vec_func.h
 *
 *  Created on: Feb 14, 2021
 *      Author: yoolatbec
 */

#ifndef SRC_ADVANCED_MATH_VEC_FUNC_H_
#define SRC_ADVANCED_MATH_VEC_FUNC_H_

#include "vec_def.h"

namespace tl {
namespace advanced {
namespace math {

vec4 make_vec4(vec4);
vec4 make_vec4(vec3);
vec4 make_vec4(vec2);
vec4 make_vec4(vec);

vec3 make_vec3(vec4);
vec3 make_vec3(vec3);
vec3 make_vec3(vec2);
vec3 make_vec3(vec);

vec2 make_vec2(vec4);
vec2 make_vec2(vec3);
vec2 make_vec2(vec2);
vec2 make_vec2(vec);

vec make_vec(vec4);
vec make_vec(vec3);
vec make_vec(vec2);
vec make_vec(vec);

vec2 to_homogeneous(vec);
vec3 to_homogeneous(vec2);
vec4 to_homogeneous(vec3);

vec to_cartesian(vec2);
vec2 to_cartesian(vec3);
vec3 to_cartesian(vec4);

}
}
}
#endif /* SRC_ADVANCED_MATH_VEC_FUNC_H_ */
