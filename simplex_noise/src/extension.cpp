
#include <dmsdk/sdk.h>

#include "simplex_noise.hpp"

/**
 * Functions
 */

static int Simplex_Seed(lua_State* L)
{
    int seed = luaL_checkinteger(L, 1);
    SimplexNoise::Seed(seed);

    return 0;
}

static int Simplex_Noise2(lua_State* L)
{
    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);

    int octaves       = 1;
    float persistence = 0.5f;
    float lacunarity  = 2.0f;

    if (lua_isnumber(L, 3))
        octaves = lua_tointeger(L, 3);
    if (lua_isnumber(L, 4))
        persistence = lua_tonumber(L, 4);
    if (lua_isnumber(L, 5))
        lacunarity = lua_tonumber(L, 5);

    if (octaves <= 0)
    {
        return luaL_error(L, "Expected octaves value > 0");
    }

    const float result = SimplexNoise::FractalNoise2(x, y, octaves, persistence, lacunarity);
    lua_pushnumber(L, result);

    return 1;
}

static int Simplex_Noise3(lua_State* L)
{
    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    float z = luaL_checknumber(L, 3);

    int octaves       = 1;
    float persistence = 0.5f;
    float lacunarity  = 2.0f;

    if (lua_isnumber(L, 4))
        octaves = lua_tointeger(L, 4);
    if (lua_isnumber(L, 5))
        persistence = lua_tonumber(L, 5);
    if (lua_isnumber(L, 6))
        lacunarity = lua_tonumber(L, 6);

    if (octaves <= 0)
    {
        return luaL_error(L, "Expected octaves value > 0");
    }

    const float result = SimplexNoise::FractalNoise3(x, y, z, octaves, persistence, lacunarity);
    lua_pushnumber(L, result);

    return 1;
}

static int Simplex_Noise4(lua_State* L)
{
    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    float z = luaL_checknumber(L, 3);
    float w = luaL_checknumber(L, 4);

    int octaves       = 1;
    float persistence = 0.5f;
    float lacunarity  = 2.0f;

    if (lua_isnumber(L, 5))
        octaves = lua_tointeger(L, 5);
    if (lua_isnumber(L, 6))
        persistence = lua_tonumber(L, 6);
    if (lua_isnumber(L, 7))
        lacunarity = lua_tonumber(L, 7);

    if (octaves <= 0)
    {
        return luaL_error(L, "Expected octaves value > 0");
    }

    const float result = SimplexNoise::FractalNoise4(x, y, z, w, octaves, persistence, lacunarity);
    lua_pushnumber(L, result);

    return 1;
}

// Functions exposed to Lua
static const luaL_reg Ext_methods[] = {
    { "seed", Simplex_Seed },
    { "noise2", Simplex_Noise2 },
    { "noise3", Simplex_Noise3 },
    { "noise4", Simplex_Noise4 },

    /* Sentinel: */
    { NULL, NULL }
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    // Register lua names
    luaL_register(L, "simplex", Ext_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

static dmExtension::Result InitializeExt(dmExtension::Params* params)
{
    LuaInit(params->m_L);

    return dmExtension::RESULT_OK;
}

static dmExtension::Result AppInitializeExt(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result FinalizeExt(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result AppFinalizeExt(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(simplex_noise, "simplex_noise", AppInitializeExt, AppFinalizeExt, InitializeExt, 0, 0, FinalizeExt)
