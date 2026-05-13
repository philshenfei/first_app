#include "first_appApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
first_appApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

first_appApp::first_appApp(const InputParameters & parameters) : MooseApp(parameters)
{
  first_appApp::registerAll(_factory, _action_factory, _syntax);
}

first_appApp::~first_appApp() {}

void
first_appApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<first_appApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"first_appApp"});
  Registry::registerActionsTo(af, {"first_appApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
first_appApp::registerApps()
{
  registerApp(first_appApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
first_appApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  first_appApp::registerAll(f, af, s);
}
extern "C" void
first_appApp__registerApps()
{
  first_appApp::registerApps();
}
