Image ALT from File entity
========

This module allows you to have a short text field on the Image type File entity
to store alt text for each image, and still use the Field UI for Image type
fields on other entities.

Choose the plain text field at Configuration > Media > Image ALT from File entity
(`admin/config/media/image-entity-alt`). The default field name is `field_alt`.

The ALT in the Image field UI for each instance will pull the default value from
the field on the File entity. This value can be overridden per instance.

If the value on the instance exactly matches the value on the file entity, the
instance value will not be saved. Each image in a multi-value field is handled
independently. Nonempty overrides, including `0`, are preserved.

Image field settings include "Use global ALT text from the file entity", enabled
by default. Uncheck it for fields that should keep empty ALT, such as decorative
images. This applies to both field rendering and the core image widget.

Rendered Image file entities use the selected field when the file display's ALT
setting is empty. An explicit file display ALT setting takes precedence.

The core editor image dialog prefills ALT for managed images with an existing
file entity. Submitted ALT is preserved, including intentionally empty text.
External image URLs without a managed file ID have no file entity to read.
This supplies an editing default; existing embedded HTML is not rewritten when
the file's ALT changes.


Requirements
------------

This module requires that the following modules are also enabled:

- Field module
- Image module
- File module


Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://docs.backdropcms.org/documentation/extend-with-modules.

- Add a plain text field to the Image file type and select it in the module settings.
- Clear caches after updating an existing installation so the settings route and
  changed hooks are discovered. Existing installations fall back to `field_alt`
  until settings are saved.


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
- [Justin Keiser](https://github.com/keiserjb)
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
