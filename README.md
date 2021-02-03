My keymap for the 34-key [Ferris][1] ([Sweep][2]) keyboard.

This repo is intended to reside at `~/qmk_firmware/keyboards/ferris/keymaps/hxy`.

It makes use of the following for the combo functionality:

1. [QMK combo improvements PR][3] by @sevanteri
2. [gBoards' combo engine][4]

With the above in place, the firmware can be compiled and flashed like so:

``` console
 $ make ferris/sweep:hxy:avrdude-split-right
```

[1]: https://github.com/pierrechevalier83/ferris
[2]: https://github.com/davidphilipbarr/sweep
[3]: https://github.com/qmk/qmk_firmware/pull/8591
[4]: http://combos.gboards.ca/
