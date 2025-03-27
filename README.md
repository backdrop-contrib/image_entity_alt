Image ALT from File entity
========

This module allows you to have a short text field on the Image type File entity
to store alt text for each image, and still use the Field UI for Image type
fields on other entities.

The short text field on the File entity must be named `field_alt`.
See https://github.com/backdrop-contrib/image_entity_alt/issues/1

The ALT in the Image field UI for each instance will pull the default value from
the field on the File entity. This value can be overridden per instance.

If the value on the instance matches the value on the file entity, the
instance value will not be saved.


Requirements
------------

This module requires that the following modules are also enabled:

- Field module
- Image mdodule
- File mdodule


Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://docs.backdropcms.org/documentation/extend-with-modules.

- Ensure you have a field on the file enity with the machine name  `field_alt`.


Issues
------

Bugs and Feature Requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/image_entity_alt/issues.


Current Maintainers
-------------------
<!--
List the current maintainer(s) of the module, and note if this module needs
new/additional maintainers.
-->

- [Jen Lampton](https://github.com/jenlampton)
- Seeking additional maintainers


Credits
-------

- Originally written for Backdrop CMS by [Jen Lampton](https://github.com/jenlampton).


License
-------
<!--
Mention what license this module is released under, and where people can find
it.
-->

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.
