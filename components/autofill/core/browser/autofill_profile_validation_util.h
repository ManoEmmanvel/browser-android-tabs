// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CORE_BROWSER_AUTOFILL_PROFILE_VALIDATION_UTIL_H_
#define COMPONENTS_AUTOFILL_CORE_BROWSER_AUTOFILL_PROFILE_VALIDATION_UTIL_H_

#include "components/autofill/core/browser/autofill_profile.h"
#include "third_party/libaddressinput/chromium/chrome_address_validator.h"

namespace autofill {
namespace profile_validation_util {

// Sets the validity state of the autofill |profile|.
void ValidateProfile(AutofillProfile* profile,
                     AddressValidator* address_validator);

// Sets the validity state of the address fields of the |profile|.
void ValidateAddress(AutofillProfile* profile,
                     AddressValidator* address_validator);

// Sets the validity state of the phone number field of the |profile|.
void ValidatePhoneNumber(AutofillProfile* profile);

// Sets the validity state of the email address field of the |profile|.
void ValidateEmailAddress(AutofillProfile* profile);

}  // namespace profile_validation_util
}  // namespace autofill

#endif  // COMPONENTS_AUTOFILL_CORE_BROWSER_AUTOFILL_PROFILE_VALIDATION_UTIL_H_
