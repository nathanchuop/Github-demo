# libhal-starter

Before getings started, if you haven't used libhal before, follow the
[Getting Started](https://libhal.github.io/2.1/) guide.

To build the project

```bash
conan build . -pr <target_name> -s build_type=<build_type>
```

For the `lpc4078` with `MinSizeRel`

```bash
conan build . -pr lpc4078 -s build_type=MinSizeRel
```

## Supported platforms

- lpc4078
- lpc4074

## How to Modify the Project

### `main.cpp`



### `application.cpp`



### `application.hpp`



### `CMakeLists.txt`



### `platforms/` directory



## Contributing

See [`CONTRIBUTING.md`](CONTRIBUTING.md) for details.

## License

Apache 2.0; see [`LICENSE`](LICENSE) for details.

## Disclaimer

This project is not an official Google project. It is not supported by
Google and Google specifically disclaims all warranties as to its quality,
merchantability, or fitness for a particular purpose.
