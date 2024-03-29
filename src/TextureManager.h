//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "ManBase.h"
#include "Texture.h"
#include "protoData.h"

class TextureManager : public ManBase
{
    //----------------------------------------------------------------------
    // Constructor
    //----------------------------------------------------------------------
private:
    TextureManager(int reserveNum = 3, int reserveGrow = 1);
    TextureManager() = delete;
    TextureManager(const TextureManager &) = delete;
    TextureManager &operator=(const TextureManager &) = delete;
    virtual ~TextureManager();

    //----------------------------------------------------------------------
    // Static Methods
    //----------------------------------------------------------------------
public:
    static void Create(int reserveNum = 3, int reserveGrow = 1);
    static void Destroy();

    static Texture *Add(const char *const pName, Texture::Name name);
    static Texture *Add(protoData &mB, Texture::Name _name);
    static Texture *Add(textureData &tB, Texture::Name _name);

    static bool Exist(Texture::Name name);
    static Texture *Find(Texture::Name name);
    static GLuint *FindID(Texture::Name name);
    static GLuint FindID(Texture::Name name, int _index);
    static void Remove(Texture *pNode);
    static void Dump();

    //----------------------------------------------------------------------
    // Private methods
    //----------------------------------------------------------------------
private:
    static TextureManager *privGetInstance();

    void privLoadTexture(protoData &mB, GLuint *&textureID);
    void privLoadTexture(textureData &mB, GLuint *&textureID);
    bool privLoadRawTexture(textureData &tD, GLuint textures);

    GLenum privGetOpenGLValue(textureData::TEXTURE_EFORMAT eFormat) const;
    GLint privGetOpenGLValue(textureData::TEXTURE_NCOMPONENT nComponent) const;

    //----------------------------------------------------------------------
    // Override Abstract methods
    //----------------------------------------------------------------------
protected:
    DLink *derivedCreateNode() override;

    //----------------------------------------------------------------------
    // Data: unique data for this manager
    //----------------------------------------------------------------------
private:
    Texture *poNodeCompare;
    static TextureManager *posInstance;
};

#endif