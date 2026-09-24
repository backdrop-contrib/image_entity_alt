Image ALT from File entity
========

This module allows you to have a short text field on the Image type File entity
to store alt text for each image, and still use the Field UI for Image type
fields on other entities.

Select a plain text field at `admin/config/media/image-entity-alt`.
The default field name is `field_alt`.

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

- Add a plain text field to the Image file type and select it in the module settings.
- Clear caches after updating to discover the new settings route and hooks.


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

Editor image dialogs prefill ALT for managed images. Submitted text, including
empty decorative ALT, is preserved. Existing embedded HTML is not rewritten.

Image field settings include "Use global ALT text from the file entity", enabled
by default. Disable it for fields that need to keep empty ALT. Core image widgets
apply this setting to each image and preserve nonempty local overrides. Only an
exact match to the fallback is removed on save.

Rendered image file entities use the configured ALT field when their image
formatter ALT is empty. Explicit display or attribute overrides take precedence.

Additional field-rendering hardening handles all image deltas, preserves nonempty
overrides (including `0`), and passes raw ALT to the image theme for escaping.
