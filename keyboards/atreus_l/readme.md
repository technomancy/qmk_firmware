Atreus L
===

A small mechanical keyboard that is based around the shape of the
human hand. This is for the left-hand side; see `atreus_r` for the
other side.

Because the two sides are independent keyboards, each side has its own
fn key. On Macs, the modifiers pressed on one side will not affect
keys pressed on the other side.

The current layout is "soft dvorak" meaning that it's intended to be
used with a machine whose OS is set to the dvorak layout. It sends
mostly qwerty keycodes, but for punctuation it sends keycodes which
will be converted by the OS into the intended code.

In addition, there is a "one-handed" mode which could hypothetically
allow the device to be used on its own with heavy use of
layering. However, this layout has not been tested much for usability.

This is for an experimental split Atreus build which uses the Atreus 1
PCB cut in half with a hacksaw. It is specifically not supported and
provided for informational purposes only.

Make example for this keyboard (after setting up your build environment):

    make atreus_l

See [build environment setup](https://docs.qmk.fm/build_environment_setup.html) then the [make instructions](https://docs.qmk.fm/make_instructions.html) for more information.
