/*
 File: point.fsh
 */
precision highp float;

uniform sampler2D u_texture;
varying lowp vec4 v_color;
void main()
{
	gl_FragColor = v_color * texture2D(u_texture, gl_PointCoord);
}
