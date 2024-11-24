#include "user_app_User.h"
#include <drogon/orm/Mapper.h>
#include <models/Users.h>
using namespace user_app;
using namespace drogon::orm; // for mapper
using namespace drogon_model::testdb;
// Add definition of your processing function here

void User::createUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
   auto json =  req->getJsonObject();
   if(!json){

    auto resp =  HttpResponse::newHttpJsonResponse(Json::Value("Invalid Json"));
    resp->setStatusCode(k400BadRequest);
    callback(resp);
    return;
   }
   std::string name = (*json)["name"].asString();
   std:: string email = (*json)["email"].asString();
    
  Users user;
  user.setName(name);
  user.setEmail(email);
  // adding user to db
  Mapper<Users> userMapper(app().getDbClient());
   try{
        userMapper.insert(user);
        auto resp =  HttpResponse::newHttpJsonResponse(user.toJson());
        resp->setStatusCode(k201Created);
        callback(resp);

   }
    catch (const std::exception &e)
    {
        auto resp = HttpResponse::newHttpJsonResponse(Json::Value("Failed to create user"));
        resp->setStatusCode(k500InternalServerError);
        resp->setContentTypeCode(CT_TEXT_HTML);
         resp->setBody("user created");
        callback(resp);
    }
}