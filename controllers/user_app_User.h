#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace user_app
{
class User : public drogon::HttpController<User>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(User::get, "/{2}/{1}", Get); // path is /user_app/User/{arg2}/{arg1}
    // METHOD_ADD(User::your_method_name, "/{1}/{2}/list", Get); // path is /user_app/User/{arg1}/{arg2}/list
    // ADD_METHOD_TO(User::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
    METHOD_ADD(User::createUser, "/users", Post);
    METHOD_ADD(User::getUser, "/users/{id}", Get);
    METHOD_ADD(User::updateUser, "/users/{id}", Put);
    METHOD_ADD(User::deleteUser, "/users/{id}", Delete);
    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
    void createUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
    void getUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int id);
    void updateUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int id);
    void deleteUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int id);
};
}
