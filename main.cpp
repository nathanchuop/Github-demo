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
