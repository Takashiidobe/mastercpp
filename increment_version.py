#!/usr/bin/env python3

import os
import sys
from enum import Enum


class Semver(Enum):
    PATCH = 1
    MINOR = 2
    MAJOR = 3


def increment(s: Semver):
    with open('VERSION', 'r') as rf, open('VERSION.swp', 'w+') as wf:
        major, minor, patch = [int(x)
                               for x in rf.readline().replace('\n', '').split('.')]

        if s == Semver.MAJOR:
            major += 1
        elif s == Semver.MINOR:
            minor += 1
        else:
            patch += 1

        new_version_string = f"{major}.{minor}.{patch}"
        exit_code = os.system(f"git tag {new_version_string}")
        if exit_code != 0:
            os.remove("VERSION.swp")
            exit(1)
        wf.write(new_version_string)
        os.remove("VERSION")
        os.rename("VERSION.swp", "VERSION")


if __name__ == "__main__":
    if len(sys.argv) == 0:
        increment(Semver.PATCH)
        exit(0)
    elif sys.argv[0].lower() == "major":
        increment(Semver.MAJOR)
    elif sys.argv[0].lower() == "minor":
        increment(Semver.MINOR)
    else:
        increment(Semver.PATCH)
