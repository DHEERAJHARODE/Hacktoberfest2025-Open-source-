from django.contrib import admin
from . models import *
# Register your models here.


@admin.register(Profile)
class ProfileAdmin(admin.ModelAdmin):
    list_display = ['user']

admin.site.register(Post)
admin.site.register(LikePost)
admin.site.register(FollowersCount)