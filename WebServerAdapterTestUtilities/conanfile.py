import os
from conans import ConanFile, tools, CMake


class WebServerAdapterTestUtilitiesConan(ConanFile):
    name = "WebServerAdapterTestUtilities"
    description = "Test utilities for library-agnostic API for C++ to work with a web server"
    url = "https://github.com/systelab/cpp-webserver-adapter"
    homepage = "https://github.com/systelab/cpp-webserver-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "web", "server", "http", "adapter", "wrapper", "test", "gtest")
    license = "MIT"
    generators = "cmake_find_package"
    settings = "os", "compiler", "build_type", "arch"
    options = {"gtest": ["1.7.0", "1.8.1", "1.10.0"]}
    default_options = "gtest=1.10.0"
    exports_sources = "*"

    def requirements(self):
        if self.options.gtest == "1.7.0":
            self.requires("gtest/1.7.0@systelab/stable")
        elif self.options.gtest == "1.8.1":
            self.requires("gtest/1.8.1")
        else:
            self.requires("gtest/1.10.0")

        self.requires("TestUtilitiesInterface/1.0.5@systelab/stable")
        if ("%s" % self.version) == "None":
            self.requires("WebServerAdapterInterface/%s@systelab/stable" % os.environ['VERSION'])
        else:
            self.requires("WebServerAdapterInterface/%s@systelab/stable" % self.version)

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".")
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include/WebServerAdapterTestUtilities", keep_path=True)
        self.copy("*WebServerAdapterTestUtilities.lib", dst="lib", keep_path=False)
        self.copy("*WebServerAdapterTestUtilities.pdb", dst="lib", keep_path=False)
        self.copy("*WebServerAdapterTestUtilities.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
