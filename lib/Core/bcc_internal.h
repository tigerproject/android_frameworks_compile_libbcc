/*
 * Copyright 2010-2012, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BCC_INTERNAL_H
#define BCC_INTERNAL_H

#include "bcc/bcc.h"

#include "bcc/BCCContext.h"
#include "bcc/RenderScript/RSCompilerDriver.h"

#if defined(__cplusplus)

#define BCC_OPAQUE_TYPE_CONVERSION(TRANSPARENT_TYPE, OPAQUE_TYPE)           \
  inline OPAQUE_TYPE wrap(TRANSPARENT_TYPE ptr) {                           \
    return reinterpret_cast<OPAQUE_TYPE>(ptr);                              \
  }                                                                         \
                                                                            \
  inline TRANSPARENT_TYPE unwrap(OPAQUE_TYPE ptr) {                         \
    return reinterpret_cast<TRANSPARENT_TYPE>(ptr);                         \
  }

namespace llvm {
  class Module;
}

namespace bcc {

class RSScript;
class RSExecutable;

struct RSScriptContext {
  // The context required in libbcc.
  BCCContext context;
  // The compiler driver
  RSCompilerDriver driver;
  // The script hold the source which is about to compile.
  RSScript *script;
  // The compilation result.
  RSExecutable *result;
};

BCC_OPAQUE_TYPE_CONVERSION(bcc::RSScriptContext *, BCCScriptRef);
BCC_OPAQUE_TYPE_CONVERSION(llvm::Module *, LLVMModuleRef);

} // namespace bcc

#undef BCC_OPAQUE_TYPE_CONVERSION

#endif // defined(__cplusplus)

#endif // BCC_INTERNAL_H