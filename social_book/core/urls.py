from django.urls import path
from .views import *

urlpatterns = [
    path('', index , name='index'),
    path('signup/', signup , name='signup'),
    path('signin/', signin , name='signin'),
    path('logout/', logout , name='logout'),
    path('setting/', setting , name='setting'),
    path('upload/', upload , name='upload'),
    path('like-post/', like_post , name='like-post'),
    path('profile/<str:pk>', profile , name='profile'),
    path('follow/', follow , name='follow'),



]