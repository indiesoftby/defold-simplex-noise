#ifndef SIMPLEX_NOISE_H
#define SIMPLEX_NOISE_H

namespace SimplexNoise
{
    void Seed(int x);
    float FractalNoise2(float x, float y, int octaves, float persistence, float lacunarity);
    float FractalNoise3(float x, float y, float z, int octaves, float persistence, float lacunarity);
    float FractalNoise4(float x, float y, float z, float w, int octaves, float persistence, float lacunarity);
} // namespace Simplex

#endif SIMPLEX_NOISE_H