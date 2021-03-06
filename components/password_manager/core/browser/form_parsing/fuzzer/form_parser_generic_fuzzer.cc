// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <stddef.h>
#include <stdint.h>

#include <memory>

#include "base/at_exit.h"
#include "base/i18n/icu_util.h"
#include "components/autofill/core/common/password_form.h"
#include "components/password_manager/core/browser/form_parsing/form_parser.h"
#include "components/password_manager/core/browser/form_parsing/fuzzer/data_accessor.h"
#include "components/password_manager/core/browser/form_parsing/fuzzer/form_data_producer.h"

namespace password_manager {

// ICU is used inside GURL parser, which is used by GenerateWithDataAccessor.
struct IcuEnvironment {
  IcuEnvironment() { CHECK(base::i18n::InitializeICU()); }
  // used by ICU integration.
  base::AtExitManager at_exit_manager;
};

IcuEnvironment* env = new IcuEnvironment();

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  DataAccessor accessor(data, size);
  FormParsingMode mode = accessor.ConsumeBit() ? FormParsingMode::FILLING
                                               : FormParsingMode::SAVING;
  autofill::FormData form_data = GenerateWithDataAccessor(&accessor);

  std::unique_ptr<autofill::PasswordForm> result =
      ParseFormData(form_data, nullptr, mode);
  if (result) {
    // Create a copy of the result -- running the copy-constructor might
    // discover some invalid data in |result|.
    autofill::PasswordForm copy(*result);
  }
  return 0;
}

}  // namespace password_manager
