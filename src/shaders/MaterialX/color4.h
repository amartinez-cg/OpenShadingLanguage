// Open Shading Language : Copyright (c) 2009-2017 Sony Pictures Imageworks Inc., et al.
// https://github.com/imageworks/OpenShadingLanguage/blob/master/LICENSE
// 
// MaterialX specification (c) 2017 Lucasfilm Ltd. 
// http://www.materialx.org/

#pragma once
#include "funcs.h"

struct color4
{
    color rgb;
    float a;
};

color4 __operator__neg__(color4 a)
{
    return color4(-a.rgb, -a.a);
}

color4 __operator__add__(color4 a, color4 b)
{
    return color4(a.rgb + b.rgb, a.a + b.a);
}

color4 __operator__add__(color4 a, int b)
{
    return a + color4(color(b), b);
}

color4 __operator__add__(color4 a, float b)
{
    return a + color4(color(b), b);
}

color4 __operator__add__(int a, color4 b)
{
    return color4(color(a), a) + b;
}

color4 __operator__add__(float a, color4 b)
{
    return color4(color(a), a) + b;
}

color4 __operator__sub__(color4 a, color4 b)
{
    return color4(a.rgb - b.rgb, a.a - b.a);
}

color4 __operator__sub__(color4 a, int b)
{
    return a - color4(color(b), b);
}

color4 __operator__sub__(color4 a, float b)
{
    return a - color4(color(b), b);
}

color4 __operator__sub__(int a, color4 b)
{
    return color4(color(a), a) - b;
}

color4 __operator__sub__(float a, color4 b)
{
    return color4(color(a), a) - b;
}

color4 __operator__mul__(color4 a, color4 b)
{
    return color4(a.rgb * b.rgb, a.a * b.a);
}

color4 __operator__mul__(color4 a, int b)
{
    return a * color4(color(b), b);
}

color4 __operator__mul__(color4 a, float b)
{
    return a * color4(color(b), b);
}

color4 __operator__mul__(int a, color4 b)
{
    return color4(color(a), a) * b;
}

color4 __operator__mul__(float a, color4 b)
{
    return color4(color(a), a) * b;
}

color4 __operator__div__(color4 a, color4 b)
{
    return color4(a.rgb / b.rgb, a.a / b.a);
}

color4 __operator__div__(color4 a, int b)
{
    float b_inv = 1/b;
    return a * color4(color(b_inv), b_inv);
}

color4 __operator__div__(color4 a, float b)
{
    float b_inv = 1/b;
    return a * color4(color(b_inv), b_inv);
}

color4 __operator_div__(int a, color4 b)
{
    return color4(color(a), a) / b;
}

color4 __operator__div__(float a, color4 b)
{
    return color4(color(a), a) / b;
}

int __operator__eq__(color4 a, color4 b)
{
    return (a.rgb == b.rgb) && (a.a == b.a);
}

int __operator__ne__(color4 a, color4 b)
{
    return (a.rgb != b.rgb) || (a.a != b.a);
}

color4 abs(color4 a)
{
    return color4(abs(a.rgb), abs(a.a));
}

color4 floor(color4 a)
{
    return color4(floor(a.rgb), floor(a.a));
}

color4 mix(color4 a, color4 b, float x )
{
    return color4(mix(a.rgb, b.rgb, x),
                  mix(a.a, b.a, x));
}

float dot(color4 a, color b)
{
    return dot(a.rgb, b);
}

color4 smoothstep(color4 edge0, color4 edge1, color4 c)
{
    return color4(smoothstep(edge0.rgb, edge1.rgb, c.rgb),
                  smoothstep(edge0.a, edge1.a, c.a));
}    

color4 smoothstep(float edge0, float edge1, color4 c)
{
    return smoothstep(color4(color(edge0), edge0), color4(color(edge1), edge1), c);
}

color4 remap(color4 c, color4 inLow, color4 inHigh, color4 outLow, color4 outHigh, int doClamp)
{
      //remap from [inLow, inHigh] to [outLow, outHigh], optionally clamping to the new range
      return color4(remap(c.rgb, inLow.rgb, inHigh.rgb, outLow.rgb, outHigh.rgb, doClamp),
                    remap(c.a, inLow.a, inHigh.a, outLow.a, outHigh.a, doClamp));
}

color4 remap(color4 c, float inLow, float inHigh, float outLow, float outHigh, int doClamp)
{
   color4 c4_inLow = color4(color(inLow), inLow);
   color4 c4_inHigh = color4(color(inHigh), inHigh);
   color4 c4_outLow = color4(color(outLow), outLow);
   color4 c4_outHigh = color4(color(outHigh), outHigh);

   return remap(c, c4_inLow, c4_inHigh, c4_outLow, c4_outHigh, doClamp);
}

color4 fgamma(color4 a, color4 b)
{
    return color4(fgamma(a.rgb, b.rgb),
                  fgamma(a.a, b.a));
}

color4 fgamma(color4 a, float b)
{
    return fgamma(a, color4(color(b), b));
}

color4 clamp(color4 c, color4 minval, color4 maxval)
{
    return color4(clamp(c.rgb, minval.rgb, maxval.rgb),
                  clamp(c.a, minval.a, maxval.a));
}

color4 clamp(color4 c, float minval, float maxval)
{
    return clamp(c, color4(color(minval), minval), color4(color(maxval), maxval));
}

color4 contrast(color4 c, color4 amount, color4 pivot)
{
    return color4(contrast(c.rgb, amount.rgb, pivot.rgb),
                  contrast(c.a, amount.a, pivot.a));
}    

color4 contrast(color4 c, float amount, float pivot)
{
    return contrast(c, color4(color(amount), amount), color4(color(pivot), pivot));
}    

color4 exponent(color4 base, color4 power)
{
    return color4(exponent(base.rgb, power.rgb),
                  exponent(base.a, power.a));
}

color4 exponent(color4 base, float power)
{
    return exponent(base, color4(color(power), power));
}

color4 max(color4 a, color4 b)
{
    return color4(max(a.rgb, b.rgb),
                  max(a.a, b.a));
}

color4 max(color4 a, float b)
{
    return color4(max(a.rgb, b),
                  max(a.a, b));
}

color4 min(color4 a, color4 b)
{
    return color4(min(a.rgb, b.rgb),
                  min(a.a, b.a));
}

color4 min(color4 a, float b)
{
    return color4(min(a.rgb, b),
                  min(a.a, b));
}

color4 fmod(color4 a, color4 b)
{
    return color4(fmod(a.rgb, b.rgb),
                  fmod(a.a, b.a));
}

color4 fmod(color4 a, int b)
{
    return fmod(a, color4(color(b), b));
}

color4 fmod(color4 a, float b)
{
    return fmod(a, color4(color(b), b));
}

color4 unpremult(color4 a)
{
    return color4(a.rgb / a.a, a.a);
}

color4 premult(color4 a)
{
    return color4(a.rgb * a.a, a.a);
}

color4 cluminance(color4 in, color lumacoeffs)
{
    float l = cluminance(in.rgb, lumacoeffs);
    return color4(color(l), in.a);
}

color4 saturate(color4 in, float amount)
{
    color hsv3 = transformc("rgb","hsv", in.rgb);
    hsv3[1] *= amount;
    color4 out = {transformc("hsv","rgb", hsv3), in.a};
    return out;
}

color4 hueshift(color4 in, float amount)
{
    color hsv3 = transformc("rgb","hsv", in.rgb);
    hsv3[0] += amount;
    hsv3[0] = fmod(hsv3[0], 1.0);
    color4 out = {transformc("hsv","rgb", hsv3), in.a};
    return out;
}

color4 cmatte(color4 fg, color4 bg)
{
    return color4((fg.rgb * fg.a) + bg.rgb * (1 - fg.a),
                   fg.a + bg.a * (1 - fg.a));
}

color4 disjointover(color4 fg, color4 bg)
{
    float summedAlpha = fg.a + bg.a;

    color4 out;
    if (summedAlpha <= 1) {
        out.rgb = fg.rgb + bg.rgb;
    }else {
        float x = (1 - fg.a) / bg.a;
        out.rgb = fg.rgb + bg.rgb * x;
        
    }

    out.a = min(summedAlpha, 1);
    return out;
}

color4 overlay(color4 fg, color4 bg)
{
    return color4(overlay(fg.rgb, bg.rgb),  
                  overlay(fg.a, bg.a));
}
