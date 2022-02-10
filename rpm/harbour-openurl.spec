Name:       harbour-openurl
Version:    1.0.0
Release:    1
License:    MPL-2.0
Summary:    Sharing plugin for opening links
Group:      System/Libraries
URL:        https://github.com/mkiol/openurl-plugin
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5Gui)
BuildRequires:  pkgconfig(Qt5Svg)
BuildRequires:  pkgconfig(Qt5Qml)
BuildRequires:  pkgconfig(Qt5Quick)
BuildRequires:  pkgconfig(nemotransferengine-qt5)
BuildRequires:  pkgconfig(rpm)
BuildRequires:  qt5-qttools
BuildRequires:  qt5-qttools-linguist

%description
Sharing plugin for opening links

%prep
%setup -q -n %{name}-%{version}

%build
%qmake5
make %{?_smp_mflags}

%install
rm -rf %{buildroot}
%qmake5_install

%files
%defattr(-,root,root,-)
%{_libdir}/nemo-transferengine/plugins/libharbouropenurlplugin.so
%{_datadir}/%{name}/*.qml
%{_datadir}/%{name}/*.svg
%{_datadir}/%{name}/translations/*.qm
