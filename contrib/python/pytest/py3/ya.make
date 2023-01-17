# Generated by devtools/yamaker (pypi).

PY3_LIBRARY()



VERSION(7.1.3)

LICENSE(MIT)

PEERDIR(
    contrib/python/attrs
    contrib/python/iniconfig
    contrib/python/packaging
    contrib/python/pluggy
    contrib/python/py
    contrib/python/tomli
)

NO_LINT()

NO_CHECK_IMPORTS(
    __tests__.*
    _pytest.*
)

PY_SRCS(
    TOP_LEVEL
    _pytest/__init__.py
    _pytest/_argcomplete.py
    _pytest/_code/__init__.py
    _pytest/_code/code.py
    _pytest/_code/source.py
    _pytest/_io/__init__.py
    _pytest/_io/saferepr.py
    _pytest/_io/terminalwriter.py
    _pytest/_io/wcwidth.py
    _pytest/_version.py
    _pytest/assertion/__init__.py
    _pytest/assertion/rewrite.py
    _pytest/assertion/truncate.py
    _pytest/assertion/util.py
    _pytest/cacheprovider.py
    _pytest/capture.py
    _pytest/compat.py
    _pytest/config/__init__.py
    _pytest/config/argparsing.py
    _pytest/config/compat.py
    _pytest/config/exceptions.py
    _pytest/config/findpaths.py
    _pytest/debugging.py
    _pytest/deprecated.py
    _pytest/doctest.py
    _pytest/faulthandler.py
    _pytest/fixtures.py
    _pytest/freeze_support.py
    _pytest/helpconfig.py
    _pytest/hookspec.py
    _pytest/junitxml.py
    _pytest/legacypath.py
    _pytest/logging.py
    _pytest/main.py
    _pytest/mark/__init__.py
    _pytest/mark/expression.py
    _pytest/mark/structures.py
    _pytest/monkeypatch.py
    _pytest/nodes.py
    _pytest/nose.py
    _pytest/outcomes.py
    _pytest/pastebin.py
    _pytest/pathlib.py
    _pytest/pytester.py
    _pytest/pytester_assertions.py
    _pytest/python.py
    _pytest/python_api.py
    _pytest/python_path.py
    _pytest/recwarn.py
    _pytest/reports.py
    _pytest/runner.py
    _pytest/scope.py
    _pytest/setuponly.py
    _pytest/setupplan.py
    _pytest/skipping.py
    _pytest/stash.py
    _pytest/stepwise.py
    _pytest/terminal.py
    _pytest/threadexception.py
    _pytest/timing.py
    _pytest/tmpdir.py
    _pytest/unittest.py
    _pytest/unraisableexception.py
    _pytest/warning_types.py
    _pytest/warnings.py
    pytest/__init__.py
    pytest/__main__.py
)

RESOURCE_FILES(
    PREFIX contrib/python/pytest/py3/
    .dist-info/METADATA
    .dist-info/entry_points.txt
    .dist-info/top_level.txt
    _pytest/py.typed
    pytest/py.typed
)

END()
