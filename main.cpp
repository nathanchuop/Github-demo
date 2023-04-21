// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <libhal-armcortex/dwt_counter.hpp>
#include <libhal-armcortex/startup.hpp>
#include <libhal-armcortex/system_control.hpp>
#include <libhal-lpc40xx/output_pin.hpp>
#include <libhal-lpc40xx/system_controller.hpp>
#include <libhal-util/steady_clock.hpp>

int
main()
{
  using namespace hal::literals;
  using namespace std::literals;

  // Initializing the data section initializes global and static variables and
  // is required for the standard C library to run.
  hal::cortex_m::initialize_data_section();
  hal::cortex_m::system_control::initialize_floating_point_unit();

  // Create a hardware counter
  auto& clock = hal::lpc40xx::clock::get();
  auto cpu_frequency = clock.get_frequency(hal::lpc40xx::peripheral::cpu);
  static hal::cortex_m::dwt_counter steady_clock(cpu_frequency);

  // Get an output pin to use as the LED pin control
  auto& led_pin = hal::lpc40xx::output_pin::get<1, 10>().value();

  while (true) {
    // (void) is used here to get the compiler to ignore the return values.
    (void)led_pin.level(true);
    (void)hal::delay(steady_clock, 500ms);
    (void)led_pin.level(false);
    (void)hal::delay(steady_clock, 500ms);
  }

  return 0;
}

namespace boost {
void
throw_exception([[maybe_unused]] std::exception const& p_error)
{
  std::abort();
}
} // namespace boost
