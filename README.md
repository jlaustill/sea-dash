<p align="center">
  <img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="20%" alt="SEA-DASH-logo">
</p>
<p align="center">
    <h1 align="center">SEA-DASH</h1>
</p>
<p align="center">
    <em>Unleash.Streamline.Build ✵ Efficient coding underwatER with sea-dash</em>
</p>
<p align="center">
	<img src="https://img.shields.io/github/license/jlaustill/sea-dash?style=default&logo=opensourceinitiative&logoColor=white&color=0080ff" alt="license">
	<img src="https://img.shields.io/github/last-commit/jlaustill/sea-dash?style=default&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/jlaustill/sea-dash?style=default&color=0080ff" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/jlaustill/sea-dash?style=default&color=0080ff" alt="repo-language-count">
</p>
<p align="center">
	<!-- default option, no dependency badges. -->
</p>

<br>

#####  Table of Contents

- [ Overview](#-overview)
- [ Features](#-features)
- [ Repository Structure](#-repository-structure)
- [ Modules](#-modules)
- [ Getting Started](#-getting-started)
    - [ Prerequisites](#-prerequisites)
    - [ Installation](#-installation)
    - [ Usage](#-usage)
    - [ Tests](#-tests)
- [ Project Roadmap](#-project-roadmap)
- [ Contributing](#-contributing)
- [ License](#-license)
- [ Acknowledgments](#-acknowledgments)

---

##  Overview

Sea-dash is an open-source cross-platform library encompassing fundamental utilities for application development. Leveraging functions such as optimization with binary representations, robust data management (through incremental circular averages), seamless floating-point transformations, and byte manipulations across various architecture ecosystems, among a range of vital components included with MatLab conversions-SeaDash simplifies high-level computation while assuring hardware acceleration within numerous embedded platforms and microcontrollers. The custom and optimized header organization ensures quality engineering and rigorous testing is carried out for fidelity within overall proposed computational and data management pipeline.

---

##  Features



---

##  Repository Structure

```sh
└── sea-dash/
    ├── LICENSE
    ├── coverage.info
    ├── extra_script.py
    ├── include
    │   ├── Bits.hpp
    │   ├── Bytes.hpp
    │   ├── Floats.hpp
    │   ├── Math.hpp
    │   ├── SeaDash.hpp
    │   └── Uint32
    ├── library.json
    ├── platformio.ini
    ├── src
    │   └── Uint32
    └── test
        ├── Bit_test.cpp
        ├── Bytes_test.cpp
        ├── Floats_test.cpp
        ├── IncrementalCircularAverage_test.cpp
        ├── Math_test.cpp
        └── dummy_test.cpp
```

---

##  Modules

<details closed><summary>.</summary>

| File | Summary |
| --- | --- |
| [library.json](https://github.com/jlaustill/sea-dash/blob/main/library.json) | Leverages sea-dash to distribute an extensive utility library under the MIT license across various software frameworks and platforms, exporting vital components such as mathematics, conversions, and data management functionality for efficient application development (v0.0.4). Written by Joshua Austill. |
| [coverage.info](https://github.com/jlaustill/sea-dash/blob/main/coverage.info) | This specific codefile, `Bit_test.cpp`, is a fundamental part of the `sea-dash` repository, which contains a C/C++ projects source with custom mathematical operations and algorithms implementations optimized for hardware acceleration in 30+ different microcontroller series using STM8, AVR-GCC and IAR Compilers' ecosystems.Positioned within the subdirectory `test`, the `Bit_test.cpp` executes unit tests for critical bits (Binary Digits) operations included in our custom header files under the `include` directory such as Bits.hpp etc., aiding in enhancing and verifying the overall fidelity of those features within our proposed computational and data management pipelines.In essence, the testing functions outlined in this `Bit_test.cpp` help assure that all operations on binary representations perform correctly through their integration within microcontroller systems firmwares. |
| [extra_script.py](https://github.com/jlaustill/sea-dash/blob/main/extra_script.py) | Generates a coverage report for CPP files during testing. Tracks source code usage (src/*.cpp) using GCOV for subsequent report analysis. Streamlined to efficiently generate data necessary for code assessment in `sea-dash`. |

</details>

<details closed><summary>src.Uint32</summary>

| File | Summary |
| --- | --- |
| [IncrementalCircularAverage.cpp](https://github.com/jlaustill/sea-dash/blob/main/src/Uint32/IncrementalCircularAverage.cpp) | Calculate and maintain average values from incremental data points, seamlessly updating as new points arrive." This C++ file serves to build the `IncrementalCircularAverage` function offered in SeaDash librarys `Uint32` namespace. Optimized for efficiency when processing large datasets repeatedly. |

</details>

<details closed><summary>test</summary>

| File | Summary |
| --- | --- |
| [Bit_test.cpp](https://github.com/jlaustill/sea-dash/blob/main/test/Bit_test.cpp) | Bits class to efficiently operate on binary representations of numerical data: Set number of bits within a specific range, Get required max bits for an integral type, Zero extracted bits from a mask; and several test cases to demonstrate: N bits at boundaries/extent of given range-Randomized mask set operations for bits around a central position inside the available width(n=4 in this example). Tests confirm accurate functionality under various conditions. |
| [dummy_test.cpp](https://github.com/jlaustill/sea-dash/blob/main/test/dummy_test.cpp) | Initiates unit test execution for project Sea-Dash in chosen development environment-either Arduino IDE or non-Arduino environment. Utilizes gtest test framework across the software architecture, enhancing code correctness through streamlined and consistent tests for functionality within this open-source endeavor. |
| [Floats_test.cpp](https://github.com/jlaustill/sea-dash/blob/main/test/Floats_test.cpp) | Tests user-defined mathematical mapping function between floats for various edges, scales, ranges, and precision scenarios. Integrates easily within the existing sea-dash Arduino library with floating point math utility functions. Ensures consistent performance in hardware design, reducing the need for precise numerical computation or extensive libraries during application development. |
| [Bytes_test.cpp](https://github.com/jlaustill/sea-dash/blob/main/test/Bytes_test.cpp) | Assure tests checking max/min uint32_т, uint64_т values are effective Each expects same byte value based on tested integers last defined bytes (e.g., uint32\_MAX results in FF FF FF FF) Further, tests confirm the behavior of minimum (all zeroes). Test case includes eight unique byte positions across uint64 values to match bit-level patterns defined within data type ranges of each respective unsigned integer type. |
| [Math_test.cpp](https://github.com/jlaustill/sea-dash/blob/main/test/Math_test.cpp) | Math** namespace across platforms as part of unit testing for sea-dash libraries. With floating point and double type, it scrutinizes both standard and boundary conditions that include addition operations under restrains provided during instantiation within testing functions like AddNRestrainedTest, thereby reinforcing the quality and dependability of mathematic function outputs within SeaDash framework. |
| [IncrementalCircularAverage_test.cpp](https://github.com/jlaustill/sea-dash/blob/main/test/IncrementalCircularAverage_test.cpp) | Inspects and evaluates the Uint32 IncrementalCircularAverage algorithm by validating its behavior under various states such as initialization, single value addition, circular buffer fill-up and underflow, large-valued inputs, average calculation in cases where average value gets overshadowed over time, handling different-sized buffers, and proper destruction. Helps refine, debug, and ensure the performance of the data-processing logic. An essential unit in its project repository focused on mathematics in embedded C++ using sea-dash framework (test/IncrementalCircularAverage_test.cpp). |

</details>

<details closed><summary>include</summary>

| File | Summary |
| --- | --- |
| [SeaDash.hpp](https://github.com/jlaustill/sea-dash/blob/main/include/SeaDash.hpp) | Compiles essential headers for SeaDashs core calculations, combining functionalities from Bit, Byte, Float, Math, and the Incremental Circular Average modules and integrates those components within its main system structure, in preparation for high-level algorithm operations within open-source project sea-dash". |
| [Bytes.hpp](https://github.com/jlaustill/sea-dash/blob/main/include/Bytes.hpp) | Facilitate utilitarian byte operations within Seadash library framework. Key component features are bite-sized processing using templates on distinct datatypes via a flexible `getNthByte()` function, empowering optimal management and manipulation of byte data across the extensive SeaDash programing landscape. |
| [Math.hpp](https://github.com/jlaustill/sea-dash/blob/main/include/Math.hpp) | Streamlines number manipulation across Sea-Dash platform by encompassing reusable mathematical functions within the Math module. Function addNRestrained", adds n to an input, ensuring outcome remains between user defined minimum and maximum bounds." |
| [Floats.hpp](https://github.com/jlaustill/sea-dash/blob/main/include/Floats.hpp) | Introduces user-defined transformation function for floating-point variables, facilitating flexible range mapping within a unified Floats namespace (SeaDash library). It serves to handle diverse requirements without disturbing the existing program framework while enabling seamless integration between floats utilities in the overall architecture. |
| [Bits.hpp](https://github.com/jlaustill/sea-dash/blob/main/include/Bits.hpp) | Manipulates bit operations efficiently; critical component in sea-dash repositorys `SeaDash` namespace. Implements template algorithms offering functionalities ranging from fetching set-bits count to configuring specific number of bits based on a given numeral using predefined offset and limits. It aims at fine-grained control to address crucial requirements for various operations in our open-source tech project. |

</details>

<details closed><summary>include.Uint32</summary>

| File | Summary |
| --- | --- |
| [IncrementalCircularAverage.hpp](https://github.com/jlaustill/sea-dash/blob/main/include/Uint32/IncrementalCircularAverage.hpp) | The Uint32/IncrementalCircularAverage.hpp module provides dynamic averaging utility within the SeaDash library by allowing accumulation of and access to sum and average of integer value data over time in a circular buffer, adaptable to predetermined buffer size for smoothing input data flux fluctuations. |

</details>

---

##  Getting Started

###  Prerequisites

**CPP**: `version x.y.z`

###  Installation

Build the project from source:

1. Clone the sea-dash repository:
```sh
❯ git clone https://github.com/jlaustill/sea-dash
```

2. Navigate to the project directory:
```sh
❯ cd sea-dash
```

3. Install the required dependencies:
```sh
❯ g++ -o myapp main.cpp
```

###  Usage

To run the project, execute the following command:

```sh
❯ ./myapp
```

###  Tests

Execute the test suite using the following command:

```sh
❯ googletest
```

---

##  Project Roadmap

- [X] **`Task 1`**: <strike>Implement feature one.</strike>
- [ ] **`Task 2`**: Implement feature two.
- [ ] **`Task 3`**: Implement feature three.

---

##  Contributing

Contributions are welcome! Here are several ways you can contribute:

- **[Report Issues](https://github.com/jlaustill/sea-dash/issues)**: Submit bugs found or log feature requests for the `sea-dash` project.
- **[Submit Pull Requests](https://github.com/jlaustill/sea-dash/blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.
- **[Join the Discussions](https://github.com/jlaustill/sea-dash/discussions)**: Share your insights, provide feedback, or ask questions.

<details closed>
<summary>Contributing Guidelines</summary>

1. **Fork the Repository**: Start by forking the project repository to your github account.
2. **Clone Locally**: Clone the forked repository to your local machine using a git client.
   ```sh
   git clone https://github.com/jlaustill/sea-dash
   ```
3. **Create a New Branch**: Always work on a new branch, giving it a descriptive name.
   ```sh
   git checkout -b new-feature-x
   ```
4. **Make Your Changes**: Develop and test your changes locally.
5. **Commit Your Changes**: Commit with a clear message describing your updates.
   ```sh
   git commit -m 'Implemented new feature x.'
   ```
6. **Push to github**: Push the changes to your forked repository.
   ```sh
   git push origin new-feature-x
   ```
7. **Submit a Pull Request**: Create a PR against the original project repository. Clearly describe the changes and their motivations.
8. **Review**: Once your PR is reviewed and approved, it will be merged into the main branch. Congratulations on your contribution!
</details>

<details closed>
<summary>Contributor Graph</summary>
<br>
<p align="left">
   <a href="https://github.com{/jlaustill/sea-dash/}graphs/contributors">
      <img src="https://contrib.rocks/image?repo=jlaustill/sea-dash">
   </a>
</p>
</details>

---

##  License

This project is protected under the [SELECT-A-LICENSE](https://choosealicense.com/licenses) License. For more details, refer to the [LICENSE](https://choosealicense.com/licenses/) file.

---

##  Acknowledgments

- List any resources, contributors, inspiration, etc. here.

---
