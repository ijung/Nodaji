"""
Definition of urls for Mine_API.
"""

from django.conf.urls import include, url
from django.contrib.auth.models import User
from Mine_API import routers, serializers, viewsets

# Uncomment the next two lines to enable the admin:
# from django.contrib import admin
# admin.autodiscover()

# Serializers define the API representation.
class UserSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = User
        fields = ('url', 'username', 'email', 'is_staff')

# ViewSets define the view behavior.
class UserViewSet(viewsets.ModelViewSet):
    queryset = User.objects.all()
    serializer_class = UserSerializer

# Routers provide an easy way of automatically determining the URL conf.
router = routers.DefaultRouter()
router.register(r'users', UserViewSet)

urlpatterns = [
    # Examples:
    # url(r'^$', Mine_API.views.home, name='home'),
    # url(r'^Mine_API/', include('Mine_API.Mine_API.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    # url(r'^admin/', include(admin.site.urls)),

    url(r'^', include(router.urls)),
    url(r'^api-auth/', include('Mine_API.urls', namespace='Mine_API')),
]
