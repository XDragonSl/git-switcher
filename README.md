[![Build Status](https://travis-ci.org/XDragonSl/git-switcher.svg?branch=master)](https://travis-ci.org/XDragonSl/git-switcher)
![GitHub release (latest SemVer)](https://img.shields.io/github/v/release/XDragonSl/git-switcher?sort=semver)
[![GitHub](https://img.shields.io/github/license/XDragonSl/git-switcher?color=blue)](LICENSE)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.0%20adopted-ff69b4.svg)](CODE_OF_CONDUCT.md)

# Git Switcher

## Description

### Overview

Global git config cannot keep a few usernames / emails, but sometimes it's necessary to use different git profiles and be able to quickly and easily switch between them. For this just need Git Switcher. The app stores user's git profiles (username & email pairs) and may switch it in global `.gitconfig` file in one command.

### Technologies

Project is using `C++` language, `C++11` standard.

## System requirements

- OS: `Windows x86 & x64`, `Linux x86 & x64`
- Software: `make`, `g++`, `git`

## Installation

```bash
git clone https://github.com/XDragonSl/git-switcher.git
cd git-switcher
make all
```

You must run these commands as Administrator (Windows) or using `sudo` (Linux).

Windows version supports using both: command line tools and Git Bash, but for using via Git Bash, users must add the following line to `%USERPROFILE%\.bash_profile` file:

```bash
alias gsw="gsw.exe"
```

Just run the following command:

```bash
echo alias gsw="gsw.exe" >> $(USERPROFILE)\.bash_profile
```

or open the file (or create it) in a text editor and add the line manually.

## Usage

### App

```bash
Options:
        -v, --version:                          Display installed version
        -h, --help:                             Display help
        -c, --current:                          Display current user email
        -l, --list:                             Display list of all user profiles
        -a, --add 
                --name <name> --email <email>:  Add new user profile
        -s, --switch 
                <number>:                       Switch user profile
```

### Make targets

- `make` - compile project (default: `build` folder)
- `make all` - compile project, install app & clean up compiled output
- `make clean` - clean up compiled output (project must be compiled earlier)
- `make install` - install app (project must be compiled earlier)
- `make update` - uninstall app, compile project, install app & clean up compiled output (app must be installed earlier)
- `make uninstall` - uninstall app (app must be installed earlier)

## Change log

[CHANGELOG.md](CHANGELOG.md)

## Contacts

If you have any questions please don't hesitate to contact me almdragonsl@gmail.com

## Copyright

&copy; 2020 Ermolenko V.A.
