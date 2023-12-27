attribute highp vec4 posAttr;
attribute highp  vec4 colAttr;
varying lowp vec4 col;
uniform highp mat4 matrix;
uniform bool mirrorEnabled_X; 
uniform bool mirrorEnabled_Y; 
void main() {
    vec4 mirroredPos = posAttr;
    if (mirrorEnabled_X) {
        mirroredPos.x *= -1.0;
    }
    if(mirrorEnabled_Y){
        mirroredPos.y *= -1.0;
    }
    col = colAttr;
    if (mirrorEnabled_X) {
        col.r = 1.0 - col.r;
    }
    if (mirrorEnabled_Y) {
        col.g = 1.0 - col.g;
    }
    gl_Position = matrix * mirroredPos;
}