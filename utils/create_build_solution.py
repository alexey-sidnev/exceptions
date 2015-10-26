import fnmatch
import os
import re
import uuid

guid_pattern = re.compile('<ProjectGuid>\{(\S*)\}<\/ProjectGuid>', re.IGNORECASE|re.DOTALL)
projectname_pattern = re.compile('<ProjectName>(\S*)<\/ProjectName>', re.IGNORECASE|re.DOTALL)

project_entry = 'Project("{UNIQUE_GUID}") = "PROJECT_NAME", "VCXPROJ_PATH", "{PROJECT_GUID}"\nEndProject\n'

build_configuration = '\t\t{PROJECT_GUID}.Debug|Win32.ActiveCfg = Debug|Win32\n\t\t{PROJECT_GUID}.Debug|Win32.Build.0 = Debug|Win32\n\t\t{PROJECT_GUID}.Release|Win32.ActiveCfg = Release|Win32\n\t\t{PROJECT_GUID}.Release|Win32.Build.0 = Release|Win32\n'

vcxproj_paths = []
vcxproj_names = []
vcxproj_guids = []
id = 1
for root, dirnames, filenames in os.walk('.'):
  for filename in fnmatch.filter(filenames, '*.vcxproj'):
    path = os.path.join(root, filename)
    new_path = os.path.join(root, filename.replace('.', '_' + str(id) + '.'))
    id += 1
    os.rename(path, new_path)
    vcxproj_file = open(new_path, 'r')
    vcxproj = vcxproj_file.read()
    vcxproj_file.close()
    guid = guid_pattern.search(vcxproj)
    if guid:
      new_guid = str(uuid.uuid4()).upper()
      old_guid = str(guid.group(1))
      new_projectname = new_path[:-len('.vcxproj')].replace('\\','_')[2:]
      
      vcxproj_guids.append(new_guid)	
      vcxproj_paths.append(new_path)
      vcxproj_names.append(new_projectname)
      
      vcxproj_file = open(new_path, 'w')
      vcxproj_file.write(re.sub(projectname_pattern, '<ProjectName>'+new_projectname+'</ProjectName>', vcxproj).replace(old_guid, new_guid))
      vcxproj_file.close()
      print 'Project: %s' % new_path

projects_string = ''
for i in range(0, len(vcxproj_paths)):
  unique_guid = str(uuid.uuid4()).upper()
  projects_string += project_entry.replace('UNIQUE_GUID', unique_guid).replace('PROJECT_NAME', vcxproj_names[i]).replace('VCXPROJ_PATH', vcxproj_paths[i]).replace('PROJECT_GUID', vcxproj_guids[i])
projects_string = projects_string[:-1]

build_configuration_string = ''
for i in range(0, len(vcxproj_paths)):
  build_configuration_string += build_configuration.replace('PROJECT_GUID', vcxproj_guids[i])
build_configuration_string = build_configuration_string[:-1]

sln_in = open('utils\\template.sln', 'r')
template_sln = sln_in.read()
sln_in.close()

sln_out = open('build_all.sln', 'w')
sln_out.write(template_sln.replace('PROJECTS', projects_string).replace('BUILD_CONFIGURATIONS',build_configuration_string))
sln_out.close()