# Simplex Noise for Defold

This extension for [the Defold game engine](https://defold.com/) provides functions to generate Simplex noise. Simplex noise is Ken Perlin's successor to classical Perlin noise that ends up doing quite a lot fewer calculations to get similar noise results.

The noise can be used as the basis for texture effects but also for animation, generating terrain heightmaps and many other things.

If you are looking for an equivalent to Unity's `Mathf.PerlinNoise` function, you've found it! While `simplex.noise2` won't produce the exact same numerical output as the Unity function (as it uses Simplex noise, not classic Perlin noise), it behaves identically in principle for generating 2D coherent noise patterns. Furthermore, this extension offers greater flexibility through adjustable parameters like octaves, persistence, and lacunarity. And the most important thing - it's FAST! ⚡️

## Setup

First add this extension as a dependency to your `game.project`:

    https://github.com/indiesoftby/defold-simplex-noise/archive/main.zip

It makes available global Lua functions `simplex.seed`, `simplex.noise2`, `simplex.noise3`, and `simplex.noise4`.

Then you can generate noise:

```lua
function init(self)
    simplex.seed(123)

    local noise = simplex.noise2(0, 0)
    print("value at (0, 0): " .. noise)
end
```

Check out the [API](#api) and the included example for more information. There is an online demo of the included example - [here](https://indiesoftby.github.io/defold-simplex-noise/).

## API

### `simplex.seed(seed)`
Sets the seed for the noise generator.

**Parameters:**
 * `seed` <kbd>(number)</kbd>: The integer seed value.

### `simplex.noise2(x, y [, octaves [, persistence [, lacunarity]]])`
Computes 2D Simplex noise, optionally with fractal parameters.

**Parameters:**
 * `x` <kbd>(number)</kbd>: The x-coordinate.
 * `y` <kbd>(number)</kbd>: The y-coordinate.
 * `octaves` <kbd>(integer, optional)</kbd>: Number of noise layers (must be > 0). Defaults to 1. It describes the number of loops that the code is run - making for finer and finer detail.
 * `persistence` <kbd>(number, optional)</kbd>: Amplitude decrease per octave. Defaults to 0.5. Describes the maximum disturbance from the undisturbed position of a wave.
 * `lacunarity` <kbd>(number, optional)</kbd>: Frequency increase per octave. Defaults to 2.0.

**Returns:**
 * `noise` <kbd>(number)</kbd>: The calculated noise value. Output range is [0, 1].

### `simplex.noise3(x, y, z [, octaves [, persistence [, lacunarity]]])`
Computes 3D Simplex noise, optionally with fractal parameters.

**Parameters:**
 * `x` <kbd>(number)</kbd>: The x-coordinate.
 * `y` <kbd>(number)</kbd>: The y-coordinate.
 * `z` <kbd>(number)</kbd>: The z-coordinate.
 * `octaves` <kbd>(integer, optional)</kbd>: Number of noise layers (must be > 0). Defaults to 1. It describes the number of loops that the code is run - making for finer and finer detail.
 * `persistence` <kbd>(number, optional)</kbd>: Amplitude decrease per octave. Defaults to 0.5. Describes the maximum disturbance from the undisturbed position of a wave.
 * `lacunarity` <kbd>(number, optional)</kbd>: Frequency increase per octave. Defaults to 2.0.

**Returns:**
 * `noise` <kbd>(number)</kbd>: The calculated noise value. Output range is [0, 1].

### `simplex.noise4(x, y, z, w [, octaves [, persistence [, lacunarity]]])`
Computes 4D Simplex noise, optionally with fractal parameters.

**Parameters:**
 * `x` <kbd>(number)</kbd>: The x-coordinate.
 * `y` <kbd>(number)</kbd>: The y-coordinate.
 * `z` <kbd>(number)</kbd>: The z-coordinate.
 * `w` <kbd>(number)</kbd>: The w-coordinate.
 * `octaves` <kbd>(integer, optional)</kbd>: Number of noise layers (must be > 0). Defaults to 1. It describes the number of loops that the code is run - making for finer and finer detail.
 * `persistence` <kbd>(number, optional)</kbd>: Amplitude decrease per octave. Defaults to 0.5. Describes the maximum disturbance from the undisturbed position of a wave.
 * `lacunarity` <kbd>(number, optional)</kbd>: Frequency increase per octave. Defaults to 2.0.

**Returns:**
 * `noise` <kbd>(number)</kbd>: The calculated noise value. Output range is [0, 1].

## License

This project is licensed under the MIT License. See the LICENSE file for details.
