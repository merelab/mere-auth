TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS = \
        mere-auth-lib     \  # mere-auth-lib
        mere-auth-cli     \  # mere-auth-cli

mere-auth-cli.depends = mere-auth-lib

OTHER_FILES += \
        etc/mere
