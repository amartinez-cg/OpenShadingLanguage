// Open Shading Language : Copyright (c) 2009-2017 Sony Pictures Imageworks Inc., et al.
// https://github.com/imageworks/OpenShadingLanguage/blob/master/LICENSE
// 
// MaterialX specification (c) 2017 Lucasfilm Ltd. 
// http://www.materialx.org/

#pragma once
#include "mx_types.h"

color smoothstep(color low, color high, color in)
{
    color out = in;
    out[0] = smoothstep(low[0], high[0], in[0]);
    out[1] = smoothstep(low[1], high[1], in[1]);
    out[2] = smoothstep(low[2], high[2], in[2]);
    return out;
}

color smoothstep(float low, float high, color in)
{
    color out = in;
    out[0] = smoothstep(low, high, in[0]);
    out[1] = smoothstep(low, high, in[1]);
    out[2] = smoothstep(low, high, in[2]);
    return out;
}

float remap(float in, float inLow, float inHigh, float outLow, float outHigh, int doClamp)
{
      //remap in from [inLow, inHigh] to [outLow, outHigh], optionally clamping to the new range
      float x = (in - inLow)/(inHigh-inLow);

      if (doClamp == 1) {
           x = clamp(x, outLow, outHigh);
      }

      return outLow + (outHigh - outLow) * x;
}

color remap(color in, color inLow, color inHigh, color outLow, color outHigh, int doClamp)
{
      //remap in from [inLow, inHigh] to [outLow, outHigh], optionally clamping to the new range
      color x = (in - inLow) / (inHigh - inLow);

      if (doClamp == 1) {
           x = clamp(x, outLow, outHigh);
      }

      return outLow + (outHigh - outLow) * x;
}

color remap(color in, float inLow, float inHigh, float outLow, float outHigh, int doClamp)
{
      //remap in from [inLow, inHigh] to [outLow, outHigh], optionally clamping to the new range
      color x = (in - inLow) / (inHigh - inLow);

      if (doClamp == 1) {
           x = clamp(x, outLow, outHigh);
      }
      
      return outLow + (outHigh - outLow) * x;
}

float fgamma(float in, float g)
{
    return sign(in) * pow(abs(in), g);
}

color fgamma(color in, color g)
{
    return sign(in) * pow(abs(in), g);
}

color fgamma(color in, float g)
{
    return sign(in) * pow(abs(in), g);
}

color premult(color in, float alpha)
{
    return in * alpha;
}

color unpremult(color in, float alpha)
{
    return in * (1 / alpha);
}

float contrast(float in, float amount, float pivot)
{
    float out = in - pivot;
    out *= amount;
    out += pivot;
    return out;
}

color contrast(color in, color amount, color pivot)
{
    color out = in - pivot;
    out *= amount;
    out += pivot;
    return out;
}

color contrast(color in, float amount, float pivot)
{
    color out = in - pivot;
    out *= amount;
    out += pivot;
    return out;
}

float exponent(float in, float amount)
{ 
    return pow(in, amount);
}

color exponent(color in, color amount)
{ 
    return pow(in, amount); 
}

color exponent(color in, float amount)
{ 
    return pow(in, amount); 
}

vector vscale(vector in, vector amount, vector center)
{
    return ((in - center) / amount) + center;
}

float magnitude(vector in)
{
    return length(in);
}

float cluminance( color in, color lumacoeffs)
{
    return dot(in, lumacoeffs);
}

float fBm( point position, int octaves, float lacunarity, float diminish, string noisetype)
{

    float out = 0;
    float amp = 1.0;
    float i;
    point p = position;
    
    for (i = 0;  i < octaves;  i += 1) {
        out += amp * noise(noisetype, p);
        amp *= diminish;  
        p *= lacunarity;
    }
    return out;
}

color fBm( point position, int octaves, float lacunarity, float diminish, string noisetype)
{

    color out = 0;
    float amp = 1.0;
    float i;
    point p = position;
    
    for (i = 0;  i < octaves;  i += 1) {
        out += amp * (color)noise(noisetype, p);
        amp *= diminish;  
        p *= lacunarity;
    }
    return out;
}

color hueshift(color in, float amount)
{
    color hsv3 = transformc("rgb","hsv", in);
    hsv3[0] += amount;
    hsv3[0] = fmod(hsv3[0], 1.0);
    color out = transformc("hsv","rgb", hsv3);
    return out;
}

float overlay(float fg, float bg)
{
    if (fg < 0.5) {
      return 2 * fg * bg;
    }
    return 1 - (1 - fg) * (1 - bg);
}

color overlay(color fg, color bg)
{
    return color(overlay(fg[0], bg[0]),
                 overlay(fg[1], bg[1]),
                 overlay(fg[2], bg[2]));     
}

closure color add(closure color in1, closure color in2)
{
    return in1 + in2;
}

closure color mix(closure color in1, closure color in2, float mask)
{
    return (in1 * mask) + (in2 * (1 - mask));
}

