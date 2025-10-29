# SON8TEST
> Specialized testing for [soneight](https://github.com/soneight) organization projects.

## Notice
> generated from [template](https://github.com/son8test/template)

## Purpose
> Ease the process of setting up automated tests for C++17 projects.

Main project repositories **should** contain only source code and minimal documentation.

## Usage
> REPO - repository name, HASH - commit hash or tag

1. Set REPO and HASH inside root [CMakeLists.txt](./CMakeLists.txt)
2. Add tests inside [CMakeLists.txt](./testing/CMakeLists.txt).
3. Create branch with appropriate pattern to trigger workflows (see [Branch Scheme](#branch-scheme-push-triggers)).

## Actions
> composite actions used in workflows

Default actions from GitHub:
- [**checkout@v5**](https://github.com/actions/checkout/tree/v5/): Check out a repository

Local:
- [**gxx-alter**](./.github/actions/gxx-alter/action.yml): Switch g++ version for Ubuntu workflows
- [**configs**](./.github/actions/configs/action.yml): Configures CMake build
- [**builder**](./.github/actions/builder/action.yml): Builds the project with CMake
- [**testing**](./.github/actions/testing/action.yml): Runs tests with CTest

Other:
- [**msvc-dev-cmd**](https://github.com/ilammy/msvc-dev-cmd/tree/v1): Setup MSVC environment

## Workflows
>Flash is shorter term for Release build.

| Workflow | Description |
|----------|-------------|
| [**Linux Min Debug**](./.github/workflows/linos-min-debug.yml) | ubuntu-22.04 g++-11 Debug Build |
| [**Linux Min Flash**](./.github/workflows/linos-min-flash.yml) | ubuntu-22.04 g++-11 Release Build |
| [**Linux Max Debug**](./.github/workflows/linos-max-debug.yml) | ubuntu-24.04 g++-14 Debug Build |
| [**Linux Max Flash**](./.github/workflows/linos-max-flash.yml) | ubuntu-24.04 g++-14 Release Build |
| [**MacOS Max Flash**](./.github/workflows/macos-max-flash.yml) | macos-15 clang default Release Build |
| [**WinOS Min Flash**](./.github/workflows/winos-min-flash.yml) | windows-2022 MSVC 14.2 Release Build |
| [**WinOS Max Debug**](./.github/workflows/winos-max-debug.yml) | windows-2025 MSVC default Debug Build |
| [**WinOS Max Flash**](./.github/workflows/winos-max-flash.yml) | windows-2025 MSVC default Release Build |

All steps in workflows are using composite actions to allow easy change one action file to apply for all workflows.

Each workflow can be triggered by creating branch name with specific pattern (see below).

## Branch Scheme (push triggers)
> Branch names to trigger specific workflows.

| Order | Parameter | Values |
|-------|-----------|--------|
| 1     | os        | linos, macos, winos |
| 2     | version   | min, max |
| 3     | build     | debug, flash |

Combining these three parameters like:
- test
- test-[os]
- test-[version]
- test-[build]
- test-[os-version]
- test-[os-build]
- test-[version-build]
- test-[os-version-build]

Will trigger specified workflows.

###### each folder MAY contain README with additional information about project
