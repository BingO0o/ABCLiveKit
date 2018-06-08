/*
 point.vsh
 */
precision highp float;
precision lowp int;

attribute float a_t;

uniform mat4 u_mvpMatrix;
uniform lowp vec4 u_color;
uniform vec2 u_startPoint;
uniform vec2 u_controlPoint1;
uniform vec2 u_controlPoint2;
uniform vec2 u_endPoint;
uniform float u_startSize;
uniform float u_endSize;
uniform float u_density;
uniform int u_method;

varying lowp vec4 v_color;

void main()
{
  if (u_method==0) {
    float t=a_t;
    float tt = t * t;
    float ttt = tt * t;
    float u = 1.0 - t;
    float uu = u * u;
    float uuu = uu * u;
    
    float b1=  uuu;
    float b2=  3.0 * uu * t;
    float b3=  3.0 * u * tt;
    float b4=  ttt;
    
    vec4 p=vec4(0.0,0.0,0.0,1.0);
    //  p.xy =  u_startPoint.xy * u_density * b1 +  u_controlPoint1.xy * u_density * b2 + u_controlPoint2.xy * u_density * b3 + u_endPoint.xy * u_density * b4;
    p.xy =  u_density * b1 * u_startPoint.xy + u_density * b2 * u_controlPoint1.xy + u_density * b3 * u_controlPoint2.xy + u_density * b4 * u_endPoint.xy;
    
    float widthDelta =u_endSize - u_startSize;
    
    float pointSize = u_density * (u_startSize + (ttt * widthDelta));
    float minSize=u_density * 1.6;
    float maxSize=u_density * 48.0;
    gl_PointSize =clamp(pointSize,minSize,maxSize);// pointSize>minSize?pointSize:minSize;
    gl_Position = u_mvpMatrix * p;
    v_color = u_color;
  }else{
    float t=a_t;
    float tt = t * t;
    float ttt = tt * t;
    
    float b1 = 0.5 * (      -ttt + 2.0 * tt - t      );
    float b2 = 0.5 * ( 3.0 * ttt - 5.0 * tt +     2.0);
    float b3 = 0.5 * (-3.0 * ttt + 4.0 * tt + t      );
    float b4 = 0.5 * (       ttt -       tt          );
    
    vec4 p=vec4(0.0,0.0,0.0,1.0);
    //  p.xy =  u_startPoint.xy * u_density * b1 +  u_controlPoint1.xy * u_density * b2 + u_controlPoint2.xy * u_density * b3 + u_endPoint.xy * u_density * b4;
    p.xy =  u_density * b1 * u_startPoint.xy + u_density * b2 * u_controlPoint1.xy + u_density * b3 * u_controlPoint2.xy + u_density * b4 * u_endPoint.xy;
    
//    ////  float widthDelta =u_endSize - u_startSize;
//    ////  float pointSize = u_density * (u_startSize + (ttt * widthDelta));
//    //
//    //  gl_PointSize = 4.0; // pointSize;
//    
//    //float f = u_useVariablePointSize * (1.0 - a_eraser);
//    float f=1.15;
//    
//    float p0p1 = distance(u_startPoint * u_density, u_controlPoint1 * u_density);
//    float p1p2 = distance(u_controlPoint1 * u_density, u_controlPoint2 * u_density);
//    
//    float startPointSize = f * (atan(1.8 - p0p1 / 4.0) + 5.0) / 5.5 + (1.0 -f);
//    float endPointSize = f * (atan(1.8 - p1p2 / 4.0) + 5.0) / 5.5 + (1.0 - f);
//    
////    float pointSize = 3.0 * u_density * (startPointSize + a_t * (endPointSize - startPointSize));
    float pointSize =u_density * u_startSize;// 3.6 * (startPointSize + a_t * (endPointSize - startPointSize));
    
    float minSize=u_density * 1.8;
    float maxSize=u_density * 48.0;
    gl_PointSize =clamp(pointSize,minSize,maxSize);// pointSize>minSize?pointSize:minSize;

   // gl_PointSize = pointSize>4.0?pointSize:4.0;
    
    
    gl_Position = u_mvpMatrix * p;
    v_color = u_color;
  }
}
