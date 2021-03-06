// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/public/test/test_navigation_ui_data.h"

#include <memory>

namespace content {

std::unique_ptr<NavigationUIData> TestNavigationUIData::Clone() const {
  return std::make_unique<TestNavigationUIData>();
}

}  // namespace content
