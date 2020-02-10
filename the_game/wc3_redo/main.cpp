#include <irrlicht.h>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#pragma comment(lib, "Irrlicht.lib")
int main() {
	IrrlichtDevice *device =
		createDevice(EDT_OPENGL, dimension2d<u32>(512, 384), 16,
			false, false, false, 0);
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo!!!");
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	guienv->addStaticText(L"Hello World! This is the Irrlicht Software engine!",
		rect<s32>(10, 10, 200, 22), true);

	IAnimatedMesh* mesh = smgr->getMesh("C:/Users/USER/Desktop/PROJECTS/wc3-redo/graphics_lib/media/sydney.md2");
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);

	if (node){
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setFrameLoop(0, 310);
		node->setMaterialTexture(0, driver->getTexture("C:/Users/USER/Desktop/PROJECTS/wc3-redo/graphics_lib/media/sydney.bmp"));
	}
	smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

	while (device->run()) {
		driver->beginScene(true, true, SColor(255, 100, 101, 140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
	device->drop();
	return 0;
}