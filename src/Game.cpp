//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "sb7.h"
#include "GameManager.h"

#include "MathEngine.h"
#include "VectApp.h"
#include "QuatApp.h"

#include "GameObject.h"
#include "ShaderObject.h"
#include "CubeMesh.h"
#include "ProtoBuffMesh.h"

#include "TextureManager.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "MeshNodeManager.h"
#include "ShaderManager.h"
#include "CameraManager.h"
#include "AnimationManager.h"
#include "ImageManager.h"

#include "Camera.h"
#include "CameraInput.h"
#include "ProtoMeshFactory.h"
#include "SphereMesh.h"
#include "GameObjectBoundingSphere.h"
#include "CameraMesh.h"

#include "GraphicsObjectHdr_Sprite.h"
#include "GraphicsObject_Sprite.h"
#include "SpriteMesh.h"
#include "GameObject2D.h"

//Animation
#include "TimerController.h"
#include "AnimController.h"
#include "Clip.h"
#include "NullMesh.h"
#include "Skeleton.h"

using namespace Azul;

namespace Azul
{
//AnimController* pAnimController;
//Clip* pWalkClip = nullptr;
//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------
Game::Game(const char *const pWindowName, const int Width, const int Height)
    :Engine(pWindowName, Width, Height)
{
    assert(pWindowName);
    this->globalTimer.Tic();
    this->intervalTimer.Tic();
}

//-----------------------------------------------------------------------------
//  Game::~Game()
//		Game Engine destructor
//-----------------------------------------------------------------------------
Game::~Game()
{
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before
//      starting to run.  This is where it can query for any required services
//      and load any non-graphic related content.
//-----------------------------------------------------------------------------
void Game::Initialize()
{
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
    InputManager::Create();
    TextureManager::Create();
    MeshNodeManager::Create();
    ShaderManager::Create();
    CameraManager::Create();
    CameraInput::Create(this->window);
    AnimationManager::Create();
    ImageManager::Create();

    //-----------------------------------------------------------------------------
    //	    Load Cameras
    //-----------------------------------------------------------------------------

    //Perspective 3D
    Camera *pCam0 = new Camera(Camera::Type::PERSPECTIVE_3D);
    pCam0->setViewport(0, 0, this->info.windowWidth, this->info.windowHeight);
    pCam0->setPerspective(35.0f, float(pCam0->getScreenWidth()) / float(pCam0->getScreenHeight()), 1.f, 10000.f);
    pCam0->setOrientAndPosition(Vect(1.0f, 0.0f, 0.0f), Vect(-1.0f, 0.0f, 0.0f), Vect(-1.0f, 12.0f, 0.0f));
    pCam0->updateCamera();
    CameraManager::Add(Camera::ID::CAMERA_0, pCam0);
    CameraManager::SetCurrent(Camera::ID::CAMERA_0, Camera::Type::PERSPECTIVE_3D);

    //Orthographic 2D
    Camera *pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);
    pCam2D->setViewport(0, 0, this->info.windowWidth, this->info.windowHeight);
    pCam2D->setOrthographic((float)-pCam2D->getScreenWidth() / 2.f, (float)pCam2D->getScreenWidth() / 2.f,
                            (float)-pCam2D->getScreenHeight() / 2.f, (float)pCam2D->getScreenHeight() / 2.f,
                            1.0f, 1000.f);
    pCam2D->setOrientAndPosition(Vect(0.f, 1.f, 0.f), Vect(0.f, 0.f, -1.f), Vect(0.f, 0.f, 2.f));
    CameraManager::Add(Camera::ID::CAMERA_1, pCam2D);
    CameraManager::SetCurrent(Camera::ID::CAMERA_1, Camera::Type::ORTHOGRAPHIC_2D);

    //-----------------------------------------------------------------------------
    //	    Load Basic Mesh
    //-----------------------------------------------------------------------------

    //Sphere
    Mesh *pSphereMesh = new SphereMesh("sphereModel.azul");
    MeshNodeManager::Add(Mesh::Name::SPHERE, pSphereMesh);
    //Cube
    Mesh *pCubeMesh = new CubeMesh("./Models/cubeMEsh.azul");
    MeshNodeManager::Add(Mesh::Name::CUBE, pCubeMesh);

    Mesh *pNullMesh = new NullMesh(nullptr);
    MeshNodeManager::Add(Mesh::Name::NULL_MESH, pNullMesh);

    // Corset
    meshData mB;
    ProtoMeshFactory::LoadMesh("Corset.mt.proto.azul", mB, Texture::Name::CORSET);
    Mesh *pCorsetMesh = ProtoMeshFactory::GetSingleMesh(mB, 0, Mesh::Name::CORSET);

    //Load Texture
    TextureManager::Add("../src/Textures/ChickenbotDiffuse.t.proto.azul", Texture::Name::CHICKEN_BOT);

    //Load mesh and set the correct Name for Skeleton.find
    Mesh *MeshArray[8];
    ProtoMeshFactory::GetMesh("walk_mesh.mt.proto.azul", MeshArray);
    MeshArray[0]->name = Mesh::Name::BONE;
    MeshArray[1]->name = Mesh::Name::BONE_R;
    MeshArray[2]->name = Mesh::Name::BONE_R_001;
    MeshArray[3]->name = Mesh::Name::BONE_R_002;
    MeshArray[4]->name = Mesh::Name::BONE_L;
    MeshArray[5]->name = Mesh::Name::BONE_L_001;
    MeshArray[6]->name = Mesh::Name::BONE_L_002;
    MeshArray[7]->name = Mesh::Name::BONE_01;

    Animation *Anim_Die_Left[8];
    ProtoMeshFactory::GetAnimation("die_left_mesh.a.proto.azul", Anim_Die_Left);

    Animation *Anim_Walk[8];
    ProtoMeshFactory::GetAnimation("walk_mesh.mt.proto.azul", Anim_Walk);

    Animation *Anim_Shot_Down[8];
    ProtoMeshFactory::GetAnimation("shot_down_mesh.a.proto.azul", Anim_Shot_Down);

    Animation *Anim_Hit_Right[8];
    ProtoMeshFactory::GetAnimation("hit_right_mesh.a.proto.azul", Anim_Hit_Right);

    Animation *Anim_Run[8];
    ProtoMeshFactory::GetAnimation("run_RM_mesh.a.proto.azul", Anim_Run);

    //-----------------------------------------------------------------------------
    //	    Load Sprites
    //-----------------------------------------------------------------------------

    SpriteMesh *pSpriteMesh = new SpriteMesh("SpriteModel.azul");
    assert(pSpriteMesh);
    MeshNodeManager::Add(Mesh::Name::SPRITE, pSpriteMesh);

    //-----------------------------------------------------------------------------
    //	    Create/Load Shaders
    //-----------------------------------------------------------------------------

    ShaderObject *pShaderObject_sprite = ShaderManager::Add(ShaderObject::Name::SPRITE, "../src/GLSL/spriteRender");
    assert(pShaderObject_sprite);

    ShaderObject *pShaderObject_color = ShaderManager::Add(ShaderObject::Name::COLOR_POSITION, "../src/GLSL/colorRender");
    assert(pShaderObject_color);

    ShaderObject *pShaderObject_Null = ShaderManager::Add(ShaderObject::Name::NULL_SHADER, "../src/GLSL/nullRender");

    ShaderObject *pShaderObject_texture = ShaderManager::Add(ShaderObject::Name::TEXTURE_SIMPLE, "../src/GLSL/textureRender");
    assert(pShaderObject_texture);

    ShaderObject *pShaderObject_textureLight = ShaderManager::Add(ShaderObject::Name::TEXTURE_POINT_LIGHT, "../src/GLSL/texturePointLightDiff");
    assert(pShaderObject_textureLight);

    ShaderObject *pShaderObject_constColor = ShaderManager::Add(ShaderObject::Name::CONST_COLOR, "../src/GLSL/constcolorRender");
    assert(pShaderObject_constColor);

    ShaderObject *pShaderObject_specLighting = ShaderManager::Add(ShaderObject::Name::SPEC_LIGHTING, "../src/GLSL/specLighting");
    assert(pShaderObject_specLighting);

    ShaderObject *pShaderObject_colorSingle = ShaderManager::Add(ShaderObject::Name::COLOR_SINGLE, "../src/GLSL/colorSingleRender");
    assert(pShaderObject_colorSingle);

    // Textures
    TextureManager::Add("../src/Textures/HotPink.t.proto.azul", Texture::Name::PINK_ERROR);
    TextureManager::Add("../src/Textures/Rocks.t.proto.azul", Texture::Name::ROCKS);
    TextureManager::Add("../src/Textures/Stone.t.proto.azul", Texture::Name::STONES);
    TextureManager::Add("../src/Textures/RedBrick.t.proto.azul", Texture::Name::RED_BRICK);
    TextureManager::Add("../src/Textures/Duckweed.t.proto.azul", Texture::Name::DUCKWEED);
    TextureManager::Add("../src/Textures/Aliens.t.proto.azul", Texture::Name::INVADERS);

    ////-----------------------------------------------------------------------------
    ////	    Create Image
    ////-----------------------------------------------------------------------------

    ImageManager::Add(Image::Name::Alien_Green, Texture::Name::INVADERS, Rect(554.f, 63.f, 98.f, 64.f));

    ////-----------------------------------------------------------------------------
    ////	    Sprite
    ////-----------------------------------------------------------------------------
    GraphicsObjectHdr_Sprite *pGraphicsHdr_Sprite = new GraphicsObjectHdr_Sprite();
    pGraphicsHdr_Sprite->Set_Sprite(pSpriteMesh,
                                    pShaderObject_sprite,
                                    ImageManager::Find(Image::Name::Alien_Green),
                                    Rect(455, 155, 150, 150));

    GameObject2D *pA1 = new GameObject2D(pGraphicsHdr_Sprite);
    GameObjectManager::Add(pA1, GameObjectManager::GetRoot());
    //pA1->posX = 900.f;
    //pA1->posY = 450.f;
    pA1->SetName("ALIEN");

    ////-----------------------------------------------------------------------------
    ////	    Basic GameObjects
    ////-----------------------------------------------------------------------------

    GraphicsObjectHdr *pGraphicsHdr = new GraphicsObjectHdr();
    pGraphicsHdr->Set_FlatTexture(pCubeMesh, pShaderObject_texture, Texture::Name::RED_BRICK);
    GameObjectBasic *pGameObject = new GameObjectBasic(pGraphicsHdr);
    GameObjectManager::Add(pGameObject, GameObjectManager::GetRoot());

    pGraphicsHdr = new GraphicsObjectHdr();
    pGraphicsHdr->Set_FlatTexture(pCorsetMesh, pShaderObject_texture, Texture::Name::CORSET);
    pGameObject = new GameObjectBasic(pGraphicsHdr);
    pGameObject->SetTrans(2.f, 2.f, 0.f);
    pGameObject->SetScale(Vect(10.f, 10.f, 10.f));
    GameObjectManager::Add(pGameObject, GameObjectManager::GetRoot());

    ////-----------------------------------------------------------------------------
    ////	    Create Animation
    ////-----------------------------------------------------------------------------

    Skeleton *pSkel = new Skeleton(MeshArray, NUM_BONES);
    pSkel->SetPos(-1.3f, 0, 0);

    Skeleton *pSkel2 = new Skeleton(MeshArray, NUM_BONES);
    pSkel2->SetPos(0, 0, 0);

    Skeleton *pSkel3 = new Skeleton(MeshArray, NUM_BONES);
    pSkel3->SetPos(1.3f, 0, 0);

    Skeleton *pSkel4 = new Skeleton(MeshArray, NUM_BONES);
    pSkel4->SetPos(0, 1.4f, 0);

    AnimationManager::Add(Anim_Die_Left, Clip::Name::DIE_LEFT, NUM_BONES);
    AnimationManager::Add(Anim_Walk, Clip::Name::WALK, NUM_BONES);
    AnimationManager::Add(Anim_Shot_Down, Clip::Name::SHOT_DOWN, NUM_BONES);
    AnimationManager::Add(Anim_Hit_Right, Clip::Name::HIT_RIGHT, NUM_BONES);
    AnimationManager::Add(Anim_Run, Clip::Name::RUN, NUM_BONES);

    AnimationManager::AddController(AnimController::AnimName::MESH1, pSkel, Clip::Name::WALK);
    AnimationManager::AddController(AnimController::AnimName::MESH2, pSkel2, Clip::Name::DIE_LEFT);
    AnimationManager::AddController(AnimController::AnimName::MESH3, pSkel3, Clip::Name::SHOT_DOWN);
    AnimationManager::AddController(AnimController::AnimName::MESH4, pSkel4, Clip::Name::HIT_RIGHT);

    AnimationManager::Demo();

    pSkel2->Hide();

    CameraManager::Update(Camera::Type::PERSPECTIVE_3D);
    CameraManager::Update(Camera::Type::ORTHOGRAPHIC_2D);

    Trace::out("Z - Reset ,  I,O - Zoom In/Out\n");
    Trace::out("ASDF - Switch Cameras\n");
    Trace::out("H: Hide B Spheres\n");

    Trace::out("-: Slow animation speed, =: Increase animation speed\n ");
    Trace::out("Q: Play animation reverse, W: Player animation forward\n ");
    Trace::out("E: Play Demo 2\n");
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, transformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update(float currentTime)
{
    this->intervalTimer.Toc();
    this->intervalTimer.Tic();

    // ------------------------------------
    // Camera update
    // ------------------------------------
    CameraManager::Update(Camera::Type::PERSPECTIVE_3D);
    CameraManager::Update(Camera::Type::ORTHOGRAPHIC_2D);
    CameraInput::Update();

    // ------------------------------------
    // Animate Me
    // ------------------------------------
    //pAnimController->Update();
    AnimationManager::Update();

    // ------------------------------------
    // GameObject update
    // ------------------------------------
    GameObjectManager::Update(this->globalTimer.Toc());
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
    GameObjectManager::Draw();
}

//------------------- ----------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{
    TextureManager::Destroy();
    InputManager::Destroy();
    GameObjectManager::Destroy();
    MeshNodeManager::Destroy();
    ShaderManager::Destroy();
    CameraManager::Destroy();
    ImageManager::Destroy();
    CameraInput::Destroy();
    AnimationManager::Destroy();
    //delete pAnimController;
    //delete pWalkClip;
}

//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
//------------------------------------------------------------------
void Game::ClearBufferFunc()
{
    const GLfloat grey[] = { 0.7f, 0.7f, 0.8f, 1.0f };
    const GLfloat one = 1.0f;

    glViewport(0, 0, info.windowWidth, info.windowHeight);
    glClearBufferfv(GL_COLOR, 0, grey);
    glClearBufferfv(GL_DEPTH, 0, &one);
}
}

// --- End of File ---