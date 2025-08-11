from conan import ConanFile
from conan.tools.meson import Meson, MesonToolchain
from conan.tools.files import copy
from conan.tools.layout import basic_layout
from conan.tools.gnu import PkgConfigDeps

class LibCLI(ConanFile):
    name = "libcli"
    version = "0.1"

    license = "Apache 2.0"
    author = "calishu"
    url = "https://github.com/calishu/libcli"
    description = "LibCLI is a command line parser for modern C++ (C++20 and beyond)"
    topics = ("cli", "parser", "cpp", "conan")

    settings = "os", "arch", "compiler", "build_type"

    exports_sources = "meson.build", "src/*", "tests/*"
    tool_requires = [
        "meson/1.7.2",
        "pkgconf/2.2.0"
    ]

    def requirements(self):
        self.requires("catch2/3.9.0", test=True)

    # def layout(self):
        # basic_layout(self)

    def generate(self):
        toolchain = MesonToolchain(self)
        toolchain.generate()

        dependencies = PkgConfigDeps(self)
        dependencies.generate()

    def build(self):
        self.output.info("Building the tests.")

        meson = Meson(self)
        meson.configure()
        meson.build()
        meson.test()

    def package(self):
        copy(self, "LICENSE", src=self.source_folder, dst=self.package_folder / "licenses")
        copy(self, "*.hpp", src=self.source_folder / "src", dst=self.package_folder / "include")

    def package_info(self):
        self.cpp_info.binddirs = []
        self.cpp_info.libdirs = []
        self.cpp_info.includedirs = ["include"]
