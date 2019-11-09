TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS = \
        mere-auth-lib     \  # mere-auth-lib
        mere-auth-app     \  # mere-auth-app

mere-auth-app.depends = mere-auth-lib


OTHER_FILES += \
        etc/mere
