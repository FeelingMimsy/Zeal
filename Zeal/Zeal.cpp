#include "Zeal.h"
ZealService* ZealService::ptr_service = nullptr;
ZealService::ZealService()
{
	//since the hooked functions are called back via a different thread, make sure the service ptr is available immediately
	ZealService::ptr_service = this; //this setup makes it not unit testable but since the caller functions of the hooks don't know the pointers I had to make a method to retrieve the base atleast
	hooks = std::shared_ptr<HookWrapper>(new HookWrapper());


	//initialize the hooked function classes
	cycle_target_hook = std::shared_ptr<CycleTarget>(new CycleTarget(this)); 
	mouse_zoom_hook = std::shared_ptr<MouseZoom>(new MouseZoom(this)); 
	looting_hook = std::shared_ptr<looting>(new looting(this));
	labels_hook = std::shared_ptr<labels>(new labels(this));
	binds_hook = std::shared_ptr<Binds>(new Binds(this));
	commands_hook = std::shared_ptr<Commands>(new Commands(this));
	main_loop_hook = std::shared_ptr<MainLoop>(new MainLoop(this));
	this->apply_patches();


	experience = std::shared_ptr<Experience>(new Experience(this));

}

void ZealService::apply_patches()
{
	const char sit_stand_patch[] = { 0xEB, 0x1A };
	mem::write(0x42d14d, sit_stand_patch); //fix pet sit shortcut crash (makes default return of function the sit/stand button not sure why its passing in 0)
}

ZealService* ZealService::get_instance()
{
	return ptr_service;
}
ZealService::~ZealService()
{
	
}