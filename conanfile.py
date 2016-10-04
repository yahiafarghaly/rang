from conans import ConanFile, tools
import os

class RangConan(ConanFile):
    '''
    Change version defined here if moving up.
    Build policy set to missing to avoid the --build flag since only a header is required.
    '''
    name = "rang"
    version = "1.0"
    url = "https://github.com/agauniyal/rang.git"
    build_policy = "missing"

    def source(self):
        self.run("git clone https://github.com/agauniyal/rang.git")
        self.run("cd rang")

    def package(self):
        self.copy("*.hpp", "include", "rang/include")
