#ifndef GRAPHICS_OBJECT_FONT_H
#define GRAPHICS_OBJECT_FONT_H

#include "GraphicsObject.h"
#include "Font.h"
#include "ShaderObject.h"

namespace Azul
{
class GraphicsObject_Font : public GraphicsObject
{
public:
    GraphicsObject_Font(const Mesh *const pMesh, const ShaderObject *const pShaderObj);
    GraphicsObject_Font() = delete;
    GraphicsObject_Font(const GraphicsObject_Font &) = delete;
    GraphicsObject_Font &operator=(const GraphicsObject_Font &) = delete;
    virtual ~GraphicsObject_Font();

    virtual void SetState() override;
    virtual void SetDataGPU() override;
    virtual void Draw() override;
    virtual void RestoreState() override;

    Matrix *poMatrix_orig;
    Matrix *poMatrix_uv;

    Texture *pTexture;

	float origWidth;
	float origHeight;

	float origPosX;
	float origPosY;
};
}

#endif