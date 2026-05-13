//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "first_appTestApp.h"
#include "first_appApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
first_appTestApp::validParams()
{
  InputParameters params = first_appApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

first_appTestApp::first_appTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  first_appTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

first_appTestApp::~first_appTestApp() {}

void
first_appTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  first_appApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"first_appTestApp"});
    Registry::registerActionsTo(af, {"first_appTestApp"});
  }
}

void
first_appTestApp::registerApps()
{
  registerApp(first_appApp);
  registerApp(first_appTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
first_appTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  first_appTestApp::registerAll(f, af, s);
}
extern "C" void
first_appTestApp__registerApps()
{
  first_appTestApp::registerApps();
}
