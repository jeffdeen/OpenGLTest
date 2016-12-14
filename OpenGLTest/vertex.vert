#version 420
in vec3 vPosition;
void main(){
    gl_Position = vec4(vPosition,1.0);
}
