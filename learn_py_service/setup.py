from setuptools import find_packages, setup

package_name = 'learn_py_service'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='darm',
    maintainer_email='5024211070@mhs.its.ac.id',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'py_srv_server_node = learn_py_service.py_service_server_node:main',
        ],
    },
)
